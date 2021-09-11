/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:44:40 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/11 17:31:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

namespace ft
{
	// ================================== //
	// std::pair must be reimplemented ✅ //
	// ================================== //
	// https://www.cplusplus.com/reference/utility/pair/

	template <class T1, class T2>
	struct pair
	{
		public :
			// Member types :
			typedef T1 first_type;
			typedef T2 second_type;

			// Member variables :
			first_type first;
			second_type second;

			pair() : first(), second()
			{
				
			}

			template<class U, class V>
			pair (const pair<U, V>& pr) : first(pr.first), second(pr.second)
			{
				
			}

			pair (const first_type& a, const second_type& b) : first(a), second(b)
			{
				
			}

			pair& operator= (const pair& pr)
			{
				if (*this == pr)
					return (*this);
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			}
	};

	// Operators:
	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	// ======================================= //
	// std::make_pair must be reimplemented ✅ //
	// ======================================= //

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
};

#endif