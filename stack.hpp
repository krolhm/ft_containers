/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:46:01 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/16 17:22:58 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <stdexcept>
# include <iostream>
# include "vector.hpp"

// http://www.cplusplus.com/reference/stack/stack/

// Your stack will use your vector class as default underlaying container, it must still be
// compatible with others containers like the STL one.

namespace ft
{
	template <typename T, typename Container = vector<T> >
	class stack;

	template <typename T, typename Container>
	bool operator== (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator!= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator> (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return lhs.c < rhs.c;
	}

	template <typename T, typename Container>
	bool operator<= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return !(lhs < rhs && lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator>= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
}

template <typename T, typename Container>
class ft::stack
{
	public:
		typedef T									value_type;
		typedef Container							container_type;
		typedef typename container_type::size_type	size_type;

		explicit stack(const container_type &ctnr = container_type()) : c(ctnr)
		{
			
		}

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return c.size();
		}

		value_type &top()
		{
			return c.back();
		}

		const value_type &top() const
		{
			return c.back();
		}

		void push(const value_type &val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

	protected:
		container_type c;
};

#endif
