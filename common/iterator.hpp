/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:17:51 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/04 18:21:24 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

namespace ft
{
	// ================================= //
	// iterator must be reimplemented ✅ //
	// ================================= //
	// https://www.cplusplus.com/reference/iterator/
	// https://www.cplusplus.com/reference/iterator/iterator/

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	template <bool is_valid, typename T>
	struct valid_iterator_tag_res
	{
		typedef T type;
		const static bool value = is_valid;
	};
	
	// Reference Tag

	class input_iterator_tag
	{ 
		
	};

	class output_iterator_tag
	{ 
		
	};

	class forward_iterator_tag
	{
		
	};

	class bidirectional_iterator_tag
	{

	};

	class random_access_iterator_tag
	{
		
	};

	// Check if iterator is valid:

	template <typename T>
	struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T>
	{
		
	};

	template <>
	struct is_ft_iterator_tagged<ft::random_access_iterator_tag> : public valid_iterator_tag_res<true, ft::random_access_iterator_tag>
	{
		
	};

	template <>
	struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag> : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag>
	{
		
	};

	template <>
	struct is_ft_iterator_tagged<ft::forward_iterator_tag> : public valid_iterator_tag_res<true, ft::forward_iterator_tag>
	{
		
	};

	template <>
	struct is_ft_iterator_tagged<ft::input_iterator_tag> : public valid_iterator_tag_res<true, ft::input_iterator_tag>
	{
		
	};

	template <>
	struct is_ft_iterator_tagged<ft::output_iterator_tag> : public valid_iterator_tag_res<true, ft::output_iterator_tag>
	{
		
	};

	template <class T>
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference reference;

		private:
			pointer __iterator;
	};

	// Invalid Iterator Error
	template <typename T>
	class InvalidIteratorException : public std::exception
	{
		private:
			std::string _error;

		public:
			InvalidIteratorException() throw()
			{
				_error = "Invalid iterator tag used : " + std::string(typeid(T).name()); 
			}

			InvalidIteratorException(const InvalidIteratorException &) throw()
			{
				
			}

			InvalidIteratorException &operator=(const InvalidIteratorException &) throw()
			{
				
			}
			
			virtual ~InvalidIteratorException() throw()
			{

			}
			
			virtual const char *what() const throw()
			{ 
				return (_error.c_str()); 
			}
	};
};

#endif