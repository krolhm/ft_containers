/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:56 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/01 14:13:01 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include <iostream>
# include "vector_iterator.hpp"
# include "../common/iterator_traits.hpp"
# include <limits>

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			typedef T			value_type;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T 			*pointer;
			typedef vector_iterator<value_type>					iterator;
			typedef vector_iterator<const value_type>			const_iterator;
			typedef vector_reverse_iterator<value_type> 		reverse_iterator;
    		typedef vector_reverse_iterator<const value_type>	const_reverse_iterator;
			typedef ptrdiff_t	difference_type;
			typedef size_t		size_type;

			~vector() {
				clear();
				::operator delete(_container);
			}

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

			// Capacity:
			size_type size() const // Return size
			{
				return _size;
			}
			size_type max_size() const // Return maximum size
			{
				return (std::min((size_type)std::numeric_limits<difference_type>::max(),
							std::numeric_limits<size_type>::max() / sizeof(value_type)));
			}
			void resize(size_type n, value_type val = value_type()) // Change size
			{
				if (n <= _size)
					_size = n;
				else
				{
					reserve(n);
					insert(end(), n - _size, val);
				}
			}
			size_type capacity() const // Return size of allocated storage capacity
			{
				return _capacity;
			}
			bool empty() const // Test whether vector is empty
			{
				return (_size == 0);
			}
			void reserve(size_type n) // Request a change in capacity
			{
				if (n > _capacity)
				{
					_capacity = n;
					pointer new_container = static_cast<pointer>(::operator new(sizeof(value_type) * n));
					std::memmove(new_container, _container, _size * sizeof(value_type));
					size_type size = _size;
					clear();
					_size = size;
					::operator delete(_container);
					_container = new_container;
				}
			}

			// Element access:
			reference operator[](size_type n) // Access element
			{
				return _container[n];
			}
			const_reference operator[](size_type n) const
			{
				return _container[n];
			}
			reference at(size_type n) // Access element
			{
				if (n >= _size)
				{
					throw std::out_of_range("ft::vector::at");
				}
				return _container[n];
			}
			const_reference at(size_type n) const
			{
				if (n >= _size)
				{
					throw std::out_of_range("ft::vector::at");
				}
				return _container[n];
			}
			reference front() // Access first element
			{
				return _container[0];
			}
			const_reference front() const
			{
				return _container[0];
			}
			reference back() // Access last element
			{
				return _container[_size - 1];
			}
			const_reference back() const
			{
				return _container[_size - 1];
			}

			// Modifiers:
			void assign(size_type count, const value_type &value) // Assign vector content
			{
				clear();
				insert(begin(), count, value);
			}
			template <typename InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}
			void push_back(const value_type &val) // Add element at the end
			{
				insert(end(), val);
			}
			void pop_back() // Delete last element
			{
				erase(end());
			}
			iterator insert(iterator position, const value_type &val)
			{
				size_type pos = position - begin();
				if (_size + 1 > _capacity)
					reserve(_capacity ? _capacity * 2 : 1);
				position = begin() + pos;
				insert(position, 1, val);
				return (iterator(_container + pos));
			}
			void insert(iterator position, size_type n, const value_type &val)
			{
				size_type pos = position - begin();
				if (_size + n > _capacity)
					reserve(_size + n);
				std::memmove(&_container[pos + n], &_container[pos], (_size - pos) * sizeof(value_type));
				for (size_type i = pos; i < pos + n; ++i)
				{
					_container[i] = val;
				}
				_size += n;
			}
			template <typename InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				size_type pos = position - begin();
				size_type s = last - first;

				if (_size + s > _capacity)
					reserve(_size + s);
				position = begin() + pos;
				for (InputIterator it = first; it != last; ++it)
				{
					position = insert(position, *it);
					position++;
				}
			}
			iterator erase(iterator position)
			{
				size_type pos = position - begin();
				if (position != end())
				{
					std::memmove(_container + pos, _container + pos + 1, (_size - pos - 1) * sizeof(value_type));
				}
				_size--;
				return (position);
			}
			iterator erase(iterator first, iterator last)
			{
				size_type pos = first - begin();
				size_type len = last - first;
				std::memmove(_container + pos, _container + pos + len, (_size - pos - len) * sizeof(value_type));
				_size -= len;
				return (first);
			}
			void swap(vector &x)
			{
				pointer container = x._container;
				size_type capacity = x._capacity;
				size_type size = x._size;

				x._container = _container;
				x._capacity = _capacity;
				x._size = _size;
				_container = container;
				_capacity = capacity;
				_size = size;
			}
			void clear()
			{
				for (size_type i = 0; i < _size; ++i)
				{
					_container[i].value_type::~value_type();
				}
				_size = 0;
			}

		private:
			pointer _container;
			size_type _capacity;
			size_type _size;
			void	init() {
				_container = static_cast<pointer>(::operator new(0));;
				_size = 0;
				_capacity = 0;
			}
	};

	// Non-member function overloads:
	// Relational operators:
	template <class T>
	bool operator== (const vector<T> &lhs, const vector<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<T>::const_iterator lhs_it = lhs.begin();
		typename vector<T>::const_iterator lhs_ite = lhs.end();
		typename vector<T>::const_iterator rhs_it = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (lhs_it != lhs_ite)
		{
			if (*lhs_it++ != *rhs_it++)
				return (false);
		}
		return (true);
	}

	template <class T>
	bool operator!= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T>
	bool operator< (const vector<T> &lhs, const vector<T> &rhs)
	{
		typename vector<T>::const_iterator lhs_it = lhs.begin();
		typename vector<T>::const_iterator lhs_ite = lhs.end();
		typename vector<T>::const_iterator rhs_it = rhs.begin();
		typename vector<T>::const_iterator rhs_ite = rhs.end();
		while (lhs_it != lhs_ite && rhs_it != rhs_ite)
		{
			if (*lhs_it < *rhs_it)
				return (true);
			else if (*lhs_it > *rhs_it)
				return (false);
			lhs_it++;
			rhs_it++;
		}
		if (lhs_it == lhs_ite && rhs_it != rhs_ite)
			return (true);
		return (false);
	}

	template <class T>
	bool operator<= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(lhs > rhs);
	}

	template <class T>
	bool operator> (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool operator>= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif