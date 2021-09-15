/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BstIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:31:15 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/15 12:55:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "Iterator.hpp"
# include "Iterator_traits.hpp"

namespace ft
{
	template <typename T, class Compare >
	class bst_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type    value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

			bst_iterator(const Compare& comp = Compare())
				: _node(), _last_node(), _comp(comp)
			{
				
			}

			bst_iterator(T * node_p, T * last_node, const Compare& comp = Compare())
				: _node(node_p), _last_node(last_node), _comp(comp)
			{
				
			}

			bst_iterator(const bst_iterator& bst_it)
			 : _node(bst_it._node), _last_node(bst_it._last_node), _comp()
			{
				
			}

			virtual ~bst_iterator()
			{
				
			}

			bst_iterator &operator=(const bst_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_node = bst_it._node;
				this->_last_node = bst_it._last_node;
				this->_comp = bst_it._comp;
				return (*this);
			}

			bool operator==(const bst_iterator& bst_it)
			{ 
				return (this->_node == bst_it._node);
			}

			bool operator!=(const bst_iterator& bst_it)
			{ 
				return (this->_node != bst_it._node);
			}

			reference operator*() const
			{ 
				return (this->_node->value); 
			}

			pointer operator->() const
			{ 
				return (&this->_node->value); 
			}

			bst_iterator& operator++(void)
			{
				T* cursor = _node;

				if (_node->right == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& _comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->right;
					if (cursor == _last_node->parent
						&& cursor->right == _last_node)
						_node = cursor;
					else
					{
						while (cursor->left != _last_node)
							cursor = cursor->left;
					}
					_node = cursor;
				}
				return (*this);
			}

			bst_iterator operator++(int)
			{
				bst_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bst_iterator& operator--(void)
			{
				T* cursor = _node;

				if (_node->left == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& !_comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->left;
					if (cursor == _last_node->parent
						&& cursor->left == _last_node)
						_node = cursor;
					else
					{
						while (cursor->right != _last_node)
							cursor = cursor->right;
					}
					_node = cursor;
				}
				return (*this);
			}

			bst_iterator operator--(int)
			{
				bst_iterator tmp(*this);
				operator--();
				return (tmp);
			}            

			T *			_node;
			T *			_last_node;
			Compare     _comp;
	};
	
	template <typename T, class Compare >
	class bst_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename T::value_type	value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

			bst_const_iterator(const Compare& comp = Compare())
				: _node(), _last_node(), _comp(comp)
			{
				
			}

			bst_const_iterator(T * node_p, T * last_node, const Compare& comp = Compare())
				: _node(node_p), _last_node(last_node), _comp(comp)
			{
				
			}

			bst_const_iterator(const bst_const_iterator& bst_it)
				: _node(bst_it._node), _last_node(bst_it._last_node), _comp()
			{
				
			}

			bst_const_iterator(const bst_iterator<T, Compare>& bst_it)
				: _node(bst_it._node), _last_node(bst_it._last_node), _comp()
			{
				
			}

			virtual ~bst_const_iterator()
			{

			}

			bst_const_iterator &operator=(const bst_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_node = bst_it._node;
				this->_last_node = bst_it._last_node;
				this->_comp = bst_it._comp;
				return (*this);
			}

			bool operator==(const bst_const_iterator& bst_it)
			{
				return (this->_node == bst_it._node);
			}

			bool operator!=(const bst_const_iterator& bst_it)
			{
				return (this->_node != bst_it._node);
			}

			reference operator*() const
			{
				return (this->_node->value);
			}

			pointer operator->() const
			{
				return (&this->_node->value);
			}

			bst_const_iterator& operator++(void)
			{
				T * cursor = _node;

				if (_node->right == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& _comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->right;
					if (cursor == _last_node->parent
						&& cursor->right == _last_node)
						_node = cursor;
					else
					{
						while (cursor->left != _last_node)
							cursor = cursor->left;
					}
					_node = cursor;
				}
				return (*this);
			}

			bst_const_iterator operator++(int)
			{
				bst_const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bst_const_iterator& operator--(void)
			{
				T * cursor = _node;

				if (_node->left == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& !_comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->left;
					if (cursor == _last_node->parent
						&& cursor->left == _last_node)
						_node = cursor;
					else
					{
						while (cursor->right != _last_node)
							cursor = cursor->right;
					}
					_node = cursor;
				}
				return (*this);
			}

			bst_const_iterator operator--(int)
			{
				bst_const_iterator tmp(*this);
				operator--();
				return (tmp);
			}            

			T			*_node;
			T			*_last_node;
			Compare		_comp;
	};
}

#endif