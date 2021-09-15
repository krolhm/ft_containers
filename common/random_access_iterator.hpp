/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:42:08 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/15 12:56:03 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "Iterator.hpp"
# include "Others.hpp"

namespace ft
{
	// Input iterator category
	// Empty class to identify the category of an iterator as an input iterator:
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef T *pointer;
			typedef T &reference;

			random_access_iterator(void) : __iterator(u_nullptr)
			{
				
			}

			random_access_iterator(pointer _iterator) : __iterator(_iterator)
			{
				
			}

			random_access_iterator(const random_access_iterator &op) : __iterator(op.__iterator)
			{
				
			}

			random_access_iterator &operator=(const random_access_iterator &op)
			{
				if (this == &op)
					return (*this);
				this->__iterator = op.__iterator;
				return (*this);
			}

			virtual ~random_access_iterator() {}

			pointer base() const
			{
				return (this->__iterator);
			}

			reference operator* (void) const
			{ 
				return (*__iterator); 
			}

			pointer operator-> (void)
			{ 
				return &(this->operator*()); 
			}

			random_access_iterator &operator++ (void)
			{
				__iterator++;
				return (*this);
			}

			random_access_iterator operator++ (int)
			{
				random_access_iterator rtn(*this);
				operator++();
				return (rtn);
			}

			random_access_iterator &operator-- (void)
			{
				__iterator--;
				return (*this);
			}

			random_access_iterator operator-- (int)
			{
				random_access_iterator rtn(*this);
				operator--();
				return (rtn);
			}

			random_access_iterator operator+ (difference_type n) const
			{ 
				return (__iterator + n); 
			}

			random_access_iterator operator- (difference_type n) const
			{ 
				return (__iterator - n);
			}

			random_access_iterator &operator+= (difference_type n)
			{
				__iterator += n;
				return (*this);
			}

			random_access_iterator &operator-= (difference_type n)
			{
				__iterator -= n;
				return (*this);
			}

			reference operator[] (difference_type n)
			{ 
				return (*(operator+(n))); 
			}

			operator random_access_iterator<const T>() const
			{
				return (random_access_iterator<const T>(this->__iterator));
			}

		private:
			pointer __iterator;
	};

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator== (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator== (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator!= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator!= (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator< (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator< (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator> (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator> (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator<= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator<= (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator>= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator>= (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T> 
	operator+ (typename ft::random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T> &rai)
	{
		return (&(*rai) + n);
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator- (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename LEFT, typename RIGHT>
	typename ft::random_access_iterator<LEFT>::difference_type
	operator- (const ft::random_access_iterator<LEFT> lhs, const ft::random_access_iterator<RIGHT> rhs)
	{
		return (lhs.base() - rhs.base());
	}

}
#endif
