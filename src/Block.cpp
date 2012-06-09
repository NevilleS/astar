#include "Block.h"
#include "Node.h"

void Block::reset()
{
	//m_path = false;
	if (m_node != NULL)
	{
		delete m_node;
		m_node = NULL;
	}
}
   



