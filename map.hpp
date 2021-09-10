/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:26 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/10 21:46:49 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include <cstring>
# include "common/others.hpp"
# include "common/random_access_iterator.hpp"
# include "common/reverse_iterator.hpp"
# include "common/lexicographical_compare.hpp"
# include "common/iterator.hpp"
# include "common/enable_if.hpp"
# include "common/is_integral.hpp"
# include "common/binary_search_tree.hpp"

namespace ft
{
	template <class Key,								  			// map::key_type
			  class T,									  			// map::mapped_type
			  class Compare = ft::less<Key>,						// map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
			  >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<key_type, mapped_type> 			value_type;
			typedef Compare										key_compare;

			class value_compare : ft::binary_function<value_type, value_type, bool>
			{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}
			};

			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer		 	pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator iterator;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator const_iterator;
			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t										size_type;
			
			// Constructors:
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _bst()
			{

			}
			
			template <class InputIterator> 
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _bst()
			{
				bool is_valid;
				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
				insert(first, last);
			}

			map(const map& x) : _alloc(x._alloc), _comp(x._comp), _bst()
			{
				insert(x.begin(), x.end());
			}

			~map()
			{
				clear();
			}

			// Operators:
			map &operator=(const map &x)
			{
				if (&x == this)
					return (*this);
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			// Iterators:
			iterator begin()
			{
				return (iterator(_bst._last_node->left, _bst._last_node));
			}
			const_iterator begin() const
			{
				return (const_iterator(_bst._last_node->left, _bst._last_node));
			}
			iterator end()
			{
				return (iterator(_bst._last_node, _bst._last_node));
			}
			const_iterator end() const
			{
				return (const_iterator(_bst._last_node, _bst._last_node));
			}
			reverse_iterator rbegin()
			{ 
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			
			// Capacity:
			bool empty() const
			{
				return (_bst._last_node->parent == _bst._last_node);
			}
			size_type size() const
			{
				return (_bst._last_node->value.first);
			}
			size_type max_size() const
			{ 
				return (_bst.max_size());
			}

			// Element access:
			mapped_type &operator[](const key_type &k)
			{
				iterator tmp = find(k);

				if (tmp == end())
					insert(ft::make_pair(k, mapped_type()));
				tmp = find(k);
				return ((*tmp).second);
			}
			
			// Modifiers:
			pair<iterator, bool> insert(const value_type &val)
			{
				return (_bst.insertPair(val));
			}
			iterator insert(iterator position, const value_type &val)
			{
				(void)position;
				return (_bst.insertPair(val).first);
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				bool is_valid;
				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());

				difference_type n = ft::distance(first, last);
				while (n--)
					insert(*(first++));
			}
			void erase (iterator position)
			{
				erase((*position).first);
			}
			size_type erase(const key_type &k)
			{
				if (find(k) == end())
					return (0);
				_bst.removeByKey(ft::make_pair(k, mapped_type()));
				return (1);
			}
			void erase(iterator first, iterator last)
			{
				while (first != last)
					erase((*(first++)).first);
			}
			void swap(map &x)
			{
				_bst.swap(x._bst);
			}
			void clear()
			{
				erase(begin(), end());
			}

			// Observers:
			key_compare key_comp() const
			{
				return (key_compare());
			}
			value_compare value_comp() const
			{
				return (value_compare(key_compare()));
			}
			
			// Operations:
			iterator find(const key_type &k)
			{
				return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
			}
			const_iterator find(const key_type &k) const
			{
				return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
			}
			size_type count(const key_type &k) const
			{
				const_iterator beg = begin();
				const_iterator end = end();

				while (beg != end)
					if ((*(beg++)).first == k)
						return (1);
				return (0);
			}
			const_iterator lower_bound(const key_type &k) const
			{
				return (const_iterator(lower_bound(k)));
			}
			iterator upper_bound(const key_type &k)
			{
				iterator beg = begin();
				iterator end = end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			}
			const_iterator upper_bound(const key_type &k) const
			{
				return (const_iterator(upper_bound(k)));
			}
			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
			{ 
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{ 
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			private:
				allocator_type							_alloc;
				Compare									_comp;
				Binary_search_tree<value_type, Compare>	_bst;
	};
}

#endif