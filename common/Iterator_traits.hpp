/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:03:55 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/15 12:55:47 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

# include "Iterator.hpp"
# include "Random_access_iterator.hpp"

namespace ft
{
	// ======================================== //
	// iterator_traits must be reimplemented ✅ //
	// ======================================== //
	// sources: https://www.cplusplus.com/reference/iterator/iterator_traits/

	template <class Iterator> 
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type       difference_type;
			typedef typename Iterator::value_type            value_type;
			typedef typename Iterator::pointer               pointer;
			typedef typename Iterator::reference             reference;
			typedef typename Iterator::iterator_category     iterator_category;
	};

	template <class T> 
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t                       difference_type;
			typedef T                               value_type;
			typedef T*                              pointer;
			typedef T&                              reference;
			typedef ft::random_access_iterator_tag  iterator_category;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t                       difference_type;
			typedef T                               value_type;
			typedef const T*                        pointer;
			typedef const T&                        reference;
			typedef ft::random_access_iterator_tag  iterator_category;
	};

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type diff = 0;
		while (first != last)
		{
			first++;
			diff++;
		}
		return (diff);
	}

};

#endif
