/*
 * Copyright (c) 2002 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Definitions for stand-alone shell for system maintainance for Linux.
 */

#ifndef	TREE_HPP_
#define	TREE_HPP_

#include <iostream>

#define ADD	0
#define SUB	1
#define MUL	2
#define DIV	3
#define NUM	4

using namespace std;
/*
 * This allows the construction of abstract arithmetic expressions and evaluation.
 *
 */
class Tree
{
public:
  // Constructeurs
  Tree();
 
  // Autres méthodes
  Tree makeTree(const char *expr);
  int arithmeticEval(Tree *tree);
  int expressionEval(const char *expr);
 
private: 
  int type,num_value;
  Tree *left,*right,*end_tree;
};

extern "C" {
     // Wrapping function that will allow interfacing C / C++
    Tree interfaceMakeTree( Tree * object, const char *expr);
	int interfaceArithmeticEval( Tree * object, Tree *tree );
	int interfaceExpressionEval(Tree * object, const char *expr);
}

#endif /* TREE_HPP_ */
