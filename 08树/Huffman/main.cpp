#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main(void)
{
	htTree *codeTree = buildTree("I love my family!");

	hlTable *codeTable = buildTable(codeTree);

	encode(codeTable, "I love my family!");

//	decode(codeTree, "");

	return 0;
}
