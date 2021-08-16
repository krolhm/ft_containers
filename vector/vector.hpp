/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:56 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/16 20:01:27 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include <iostream>
# include "vector_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T *pointer;
			typedef vector_iterator<value_type> iterator;
			typedef vector_iterator<const value_type> const_iterator;
			typedef vector_reverse_iterator<value_type> reverse_iterator;
    		typedef vector_reverse_iterator<const value_type> const_reverse_iterator;
			typedef size_t size_type;

			// Iterators:
			iterator begin()
			{
				return (iterator(_container));
			}
			const_iterator begin() const
			{
				return (const_iterator(_container));
			}
			iterator end()
			{
				return (iterator(_container + _size));
			}
			const_iterator end() const
			{
				return (const_iterator(_container + _size));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(_container + _size));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_container + _size));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(_container));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_container));
			}

		private:
			pointer _container;
			size_type _capacity;
			size_type _size;
	};
}

#endif