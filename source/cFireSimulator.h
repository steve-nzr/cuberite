#pragma once
#include "cSimulator.h"
#include "cBlockEntity.h"
#include <list>

class Vector3i;
class cWorld;
class cFireSimulator : public cSimulator
{
public:
	cFireSimulator( cWorld* a_World );
	~cFireSimulator();

	virtual void Simulate( float a_Dt );

	virtual bool IsAllowedBlock( char a_BlockID );

	virtual bool IsBurnable( char a_BlockID );
	virtual bool IsForeverBurnable( char a_BlockID );
	virtual bool FiresForever( char a_BlockID );

protected:
	virtual void AddBlock(int a_X, int a_Y, int a_Z);
	virtual void _AddBlock(int a_X, int a_Y, int a_Z);
	virtual bool BurnBlockAround(int a_X, int a_Y, int a_Z);
	virtual bool BurnBlock(int a_X, int a_Y, int a_Z);

	typedef std::list <Vector3i> BlockList;
	BlockList *m_Blocks;
	BlockList *m_Buffer;

	BlockList *m_BurningBlocks;
};