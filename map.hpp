/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:26 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/10 19:39:36 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <iostream>
# include "common/pair.hpp"
# include "common/others.hpp"

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
			
			
	};
}

#endif