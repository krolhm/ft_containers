/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:09:16 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/15 12:56:08 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

# include "Iterator_traits.hpp"

namespace ft
{
	// https://www.cplusplus.com/reference/iterator/reverse_iterator/

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator() : __iterator()
			{
				
			}

			explicit reverse_iterator(iterator_type it) : __iterator(it)
			{
				
			}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : __iterator(rev_it.base())
			{
				
			}

			virtual ~reverse_iterator() // Destructor
			{
				
			}

			iterator_type base() const // Return base iterator
			{
				return (__iterator);
			}
			
			// Operators:
			reference operator*() const
			{
				iterator_type tmp = __iterator;
				return (*(--tmp));
			}

			reverse_iterator operator+ (difference_type n) const
			{ 
				return (reverse_iterator(__iterator - n)); 
			}

			reverse_iterator &operator++ ()
			{
				--__iterator;
				return (*this);
			}

			reverse_iterator operator++ (int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			reverse_iterator &operator+= (difference_type n)
			{
				__iterator -= n;
				return (*this);
			}

			reverse_iterator operator- (difference_type n) const
			{ 
				return (reverse_iterator(__iterator + n));
			}

			reverse_iterator &operator-- ()
			{
				++__iterator;
				return (*this);
			}

			reverse_iterator operator-- (int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator &operator-= (difference_type n)
			{
				__iterator += n;
				return (*this);
			}

			pointer operator-> () const
			{ 
				return &(operator*());
			}

			reference operator[] (difference_type n) const
			{ 
				return (this->base()[-n - 1]);
			}

		private:
			iterator_type __iterator;
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() == rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator== (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() != rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator!= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() > rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator< (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator<= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() < rhs.bash());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator> (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator>= (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{ 
		return (rev_it + n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{ 
		return (lhs.base() - rhs.base()); 
	}

	/* For reverser_iterator - const_reverse_iterator */
	template <class Iterator_L, class Iterator_R>
	bool operator- (const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{ 
		return (lhs.base() - rhs.base());
	}

};

#endif
