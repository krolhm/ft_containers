/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:35:01 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/10 21:57:47 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "others.hpp"

// source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

/*
**				8
**			  /   \
**			 3	  10
**		   /   \	\
**		  1		6	14
**			   / \
**			  4	  7
**
**	• The left subtree of a node contains only nodes with keys lesser than the node’s key.
**	• The right subtree of a node contains only nodes with keys greater than the node’s key.
**	• The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.
*/

namespace ft
{
	template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
			  class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class binary_search_tree
	{
		public:
			typedef binary_search_tree	self;
			typedef self				&self_reference;
			typedef T					value_type;
			typedef Node				node_type;
			typedef Node				*node_pointer;
			typedef Node_Alloc			node_alloc;
			typedef ft::bst_iterator<Node, Compare>			iterator;
			typedef ft::bst_const_iterator<Node, Compare>	const_iterator;
			typedef size_t				size_type;

			binary_search_tree(const node_alloc &node_alloc_init = node_alloc())
				: _node_alloc(node_alloc_init)
			{
				_last_node = _node_alloc.allocate(1);
				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			}

			~binary_search_tree()
			{
				_node_alloc.destroy(_last_node);
				_node_alloc.deallocate(_last_node, 1);
			}

			// last_node parent = root of tree
			// last_node right = last node
			// last_node left = first node
			node_pointer	_last_node;
			node_alloc		_node_alloc;
	};
}

#endif