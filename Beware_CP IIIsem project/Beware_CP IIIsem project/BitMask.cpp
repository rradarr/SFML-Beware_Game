#include "BitMask.h"

BitMask::BitMask()
{
	bits = 0;
}

BitMask::~BitMask()
{
}

void BitMask::SetMask(BitMask & other)
{
	bits = other.GetMask();
}

uint32_t BitMask::GetMask() const
{
	return bits;
}

bool BitMask::GetBit(int pos) const
{
	uint32_t mask = 1;
	mask = mask << pos;
	return bits & mask;
}

void BitMask::SetBit(int pos, bool on)
{
	if (on)
		SetBit(pos);
	else
		ResetBit(pos);
}

void BitMask::SetBit(int pos)
{
	bits = bits | 1 << pos;
}

void BitMask::ResetBit(int pos)
{
	bits = bits & ~(1 << pos);
}

void BitMask::Clear()
{
	bits = 0;
}
