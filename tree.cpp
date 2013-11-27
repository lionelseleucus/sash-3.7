#include "tree.hpp"
#include <stdio.h>
#include <ctype.h>

using namespace std;
Tree::Tree():type(0),num_value(0),left(NULL),right(NULL),end_tree(NULL){}

Tree Tree::makeTree(const char *expr){
	Tree *tree, *end_tree, *leaf1, *leaf2;
	const char *ch = expr;
	
	while (*ch != '\0')
	{
    	if (isdigit(*ch))
		{
			leaf1 = new Tree;
   	  	  	leaf1->type = NUM;
			leaf1->num_value = atoi(ch);
		  
   	  		while (isdigit(*ch)){
   	  			ch++;
   	  		}
   	    		
   	  	  	if (*ch == '\0')
   	    	{
				if (tree == NULL){
   	      	  		tree = leaf1;
   	      	  	}
			 	else{
			 		end_tree->right = leaf1;
			 	}
   	    	}
   		}
        else
   		{
			leaf2 = new Tree;
			if(*ch == '+'){
				leaf2->type = ADD;
			}else if(*ch == '-'){
				leaf2->type = SUB;
			}else if(*ch == '*'){
				leaf2->type = MUL;
			}else{
				leaf2->type = DIV;
			}

   	  	    if (leaf2->type == ADD || leaf2->type == SUB)
   	        {
   	      	  if (tree == NULL)
   			  {
				  tree = leaf2;
				  tree->left = leaf1;
				  end_tree = tree;
   			  }
			  else
			  {
				  end_tree->right = leaf1;
				  leaf2->left = tree;
				  end_tree = tree = leaf2;
   			  }
		  }
		  else
		  {
			  if (tree == NULL)
			  {
				  tree = leaf2;
				  tree->left = leaf1;
				  end_tree = tree;		  
			  }
			  else
			  {
				  end_tree->right = leaf2;
				  leaf2->left = leaf1;
				  end_tree = leaf2;
			  }
		  }
		  ch++;
   		}
       }
	   return *tree;
}

int Tree::arithmeticEval(Tree *tree){

	if(tree->type == NUM){
		return tree->num_value;
	}else if(tree->type == ADD){
		return arithmeticEval(tree->left) + arithmeticEval(tree->right);
	}else if(tree->type == SUB){
		return arithmeticEval(tree->left) - arithmeticEval(tree->right);
	}else if(tree->type == MUL){
		return arithmeticEval(tree->left) * arithmeticEval(tree->right);
	}else if(tree->type == DIV){
		return arithmeticEval(tree->left) / arithmeticEval(tree->right);
	}else{
		return 0;
	}
}

int Tree::expressionEval(const char *expr){
	Tree tree = makeTree(expr);
	int res = arithmeticEval(&tree);
	return res;
}

Tree interfaceMakeTree( Tree * object, const char *expr){
	return object->makeTree(expr);
}
int interfaceArithmeticEval( Tree * object, Tree *tree ){
	return object->arithmeticEval(tree);
}
int interfaceExpressionEval(Tree * object, const char *expr){
	return object->expressionEval(expr);
}