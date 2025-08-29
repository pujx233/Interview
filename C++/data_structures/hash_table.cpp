#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional> // Required for std::hash
#include <future>
#include <mutex>
#include <shared_mutex>

using namespace std;

namespace interview {

template<typename K, typename V>
struct LinkNode {
  LinkNode() = default;
  LinkNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}

  K key;
  V value;
  LinkNode *next;
};

template <typename K, typename V>
class HashTable {
public:
  HashTable() : size_(0) {
    table_.resize(INIT_BUCKET_SIZE, nullptr);
  }

  ~HashTable() {
    for (auto head : table_) {
      while (head) {
        auto cur = head;
        head = head->next;
        delete cur;
      }
    }
  }

  HashTable(const HashTable&) = delete;
  HashTable& operator=(const HashTable&) = delete;

  size_t size() const {
    return size_;
  }

  void insert(const K& key, const V& value) {
    lock_guard<mutex> lock(m);
    cout << "insert(" << key << ", " << value << ")" << endl;
    if (load_factor() > max_load_factor_) {
      rehash();
    }

    auto iter = find(key);
    if (iter != nullptr) {
      iter->value = value;
    } else {
      size_t loc = hash_(key) % table_.size();
      auto newNode = new LinkNode<K, V>(key, value);
      newNode->next = table_[loc]; // Corrected logic
      table_[loc] = newNode;
      ++size_;
    }
  }

  V& operator[](const K& key) {
    if (load_factor() > max_load_factor_) {
      rehash();
    }

    auto* node = find(key);
    if (node) {
      return node->value; // Corrected member name
    }

    size_t loc = hash_(key) % table_.size();
    auto* new_node = new LinkNode<K, V>(key, V{});

    new_node->next = table_[loc];
    table_[loc] = new_node;
    ++size_;

    return table_[loc]->value; // Corrected member name
  }

  V at(const K& key) const {
    auto iter = find(key);
    if (iter == nullptr) {
      throw std::out_of_range("Key not found in HashTable");
    }
    return iter->value; // Corrected member name
  }

  bool erase(const K& key) {
    size_t loc = hash_(key) % table_.size();
    auto *iter = table_[loc];
    LinkNode<K, V> *prev = nullptr;
    while (iter) {
      if (iter->key == key) {
        break;
      }
      prev = iter;
      iter = iter->next;
    }

    if (iter == nullptr) {
      return false;
    }

    if (prev == nullptr) {
      table_[loc] = iter->next;
    } else {
      prev->next = iter->next;
    }
    --size_;
    delete iter;
    return true;
  }

  size_t count(const K& key) {
    auto iter = find(key);
    if (iter != nullptr) {
      return 1;
    } else {
      return 0;
    }
  }

private:
  // Non-const version of find
  LinkNode<K, V>* find(const K& key) {
    size_t index = hash_(key) % table_.size();
    auto* iter = table_[index];
    while (iter != nullptr && iter->key != key) {
      iter = iter->next;
    }
    return iter;
  }

  // Const version of find
  const LinkNode<K, V>* find(const K& key) const {
    size_t index = hash_(key) % table_.size();
    const auto* iter = table_[index];
    while (iter != nullptr && iter->key != key) {
      iter = iter->next;
    }
    return iter;
  }

  float load_factor() const {
    return table_.empty() ? 0.0f : static_cast<float>(size_) / table_.size();
  }

  void rehash() {
    size_t new_bucket_count = table_.size() * 2 + 1;
    std::vector<LinkNode<K, V>*> new_table(new_bucket_count, nullptr);

    for (size_t i = 0; i < table_.size(); ++i) {
      auto current = table_[i];
      while (current) {
        auto next_node = current->next;

        size_t new_loc = hash_(current->key) % new_bucket_count; // Corrected typo
        current->next = new_table[new_loc];
        new_table[new_loc] = current;

        current = next_node;
      }
    }
    table_ = std::move(new_table);
  }

  const size_t INIT_BUCKET_SIZE = 13;
  const float max_load_factor_ = 0.75f;

  vector<LinkNode<K, V> *> table_;
  std::hash<K> hash_; // Corrected type to std::hash
  size_t size_;
  mutable mutex m;
};

}


int main() {
  interview::HashTable<string, int> m;
  m.insert("hello", 1);
  m.insert("world", 2);
  m["hello"] = 100;
  m["test"] = 200;

  std::cout << "m[\"hello\"]=" << m["hello"] << std::endl;
  std::cout << "m[\"world\"]=" << m["world"] << std::endl;
  std::cout << "m[\"test\"]=" << m["test"] << std::endl;
  std::cout << "Current size: " << m.size() << std::endl;

  m.erase("world");
  std::cout << "After erasing 'world', size is: " << m.size() << std::endl;
  string key = "world";
  std::cout << "Count of 'world': " << m.count(key) << std::endl;

  try {
    std::cout << "m.at(\"hello\")=" << m.at("hello") << std::endl;
    m.at("world");
  } catch (const std::out_of_range& e) {
    std::cout << "Trying to access 'world' with at(): " << e.what() << std::endl;
  }

  return 0;
}