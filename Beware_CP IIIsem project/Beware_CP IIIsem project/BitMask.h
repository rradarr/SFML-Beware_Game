#pragma once

#include <stdint.h>

/**
*The class represents a bitmask containing 32 bits. In this program these bits
*represent states of inputs taken from the keyboard.
*/
class BitMask
{
public:
	/// Construct a bitmask with all bits set to 0.
	BitMask();

	/// Deconstruct the bitmask.
	~BitMask();

	/// Overwrite this bitmask with contents of another.
	void SetMask(BitMask& other);

	/// Return binary representation of bitmask.
	uint32_t GetMask() const;

	/// Return true if bit at pos = 1, else false.
	bool GetBit(int pos) const;

	/// Set bit at specified pos to 1 or 0 (true or false).
	void SetBit(int pos, bool on);

	/// Set bit at pos to 1.
	void SetBit(int pos);

	/// Set bit at pos to 0.
	void ResetBit(int pos);

	/// Set all bits to 0.
	void Clear();

private:
	///The bits of the bitmask
	uint32_t bits;
};

