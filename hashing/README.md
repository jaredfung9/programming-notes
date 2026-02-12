# HASHING
## CONSIDERATIONS
* What is this hash used for? Does it need to be cryptographically secure?
* What is the processing power and memory available on the target system?
* Can you tolerate hash collisions?
* Does this system rely on cryptography? Use a trusted cryptographic library!
## COMMON ALGORITHMS FOR PERSONAL PROJECTS:
* SHA-256: Cryptographically Secure, used to demo cryptography concepts (hashes, HMACs, certificates), but it's better to use a trusted cryptographic library for real projects!
* FNV-1A: general-use hash; simple to implement, low computation and memory cost; not secure, but if you need to guarantee security you should not be handrolling your cryptographical functions.
* Learn one general-use; understand why cryptographic hashes are important and their use-cases
## FNV-1A
// DO NOT USE FOR CRYPTOGRAPHY!!!
// All VARs, except for data_byte, are 64-bit unsigned integers
// FNV_OFFSET_BASIS = 0xcbf29ce484222325
// FNV_PRIME = 0x100000001b3
// FNV_OFFSET_BASIS and FNV_PRIME are adjusted depending on target_size of the hash
// MUL returns lower 64-bits of the product
// XOR only operates on the lower 8-bits of the hash value
// hash is a 64-bit unsigned integer

fnv-1a(data) -> hash
	hash := FNV_OFFSET_BASIS

	for each data_byte in data:
		hash := (XOR hash data_byte)
		hash := (MUL hash FNV_PRIME)

	return hash
