#include <unordered_map>
#include <vector>

#ifndef BLACKMARLINCPP
#define BLACKMARLINCPP
class BlackMarlin {
public:
	// BlackMarlin's default constructor.
	BlackMarlin();
	// BlackMarlin's destructor.
	~BlackMarlin();
	// Returns the value of a key if it exists. If it does not exist, returns a nullptr.
	const std::string* Get(const std::string& p_key) const;
	// Sets the key and the value in the map. If the key already exists and the intention was to overwrite the value, the method Overwrite should be used instead.
	void Set(std::string p_key, std::string* p_value);
	// Sets the key and the value in the map to be deleted later in the specified amount of seconds.
	void SetToDeleteLater(std::string p_key, std::string* p_value, const uint16_t& p_seconds);
	// Overwrites the value to the key. If the key does not exist, nothing happens.
	void Overwrite(std::string p_key, std::string* p_value);
	// Deletes the pointer to the string and the "bucket" in the map.
	void Delete(const std::string& p_key);
	// Returns true if the key exists in the map; false otherwise.
	const bool Exists(const std::string& p_key) const;
	// Returns the number of items in the map.
	const size_t Count() const;
	// Frees all pointers and buckets in the map.
	void Flush();
private:
	// The main std::unordered_map for storing the values (string to string pointer).
	std::unordered_map<std::string, std::string*> m_dict;
	// Deletes the pointer in the specified time in seconds.
	void DeleteIn(const std::string& p_key, const uint16_t& p_seconds);
};
#endif