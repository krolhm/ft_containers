/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:42:20 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/11 17:36:18 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

// https://www.cplusplus.com/reference/cstddef/nullptr_t/

static class nullptr_t
{
	public:
		template<class T>
		operator T*() const
		{ 
			return (0); 
		}

		template<class C, class T>
		operator T C::*() const 
		{ 
			return (0); 
		}

	private:
		void operator&() const;

} u_nullptr = {};

namespace ft
{
	template <typename T>
	std::string to_string(T n)
	{
		std::ostringstream str;
		str << n;
		return (str.str());
	}

	// Copy from: https://www.cplusplus.com/reference/functional/binary_function/
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	// Copy from: https://www.cplusplus.com/reference/functional/less/
	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const
		{ 
			return x < y;
		}
	};

	template <typename T>
	struct BST_Node
	{
		public:
			typedef T	value_type;
			value_type	value;
			BST_Node	*parent;
			BST_Node	*left;
			BST_Node	*right;

			BST_Node() : value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
			{
				
			}

			BST_Node(BST_Node *parent = u_nullptr, BST_Node *left = u_nullptr, BST_Node *right = u_nullptr)
				: value(), parent(parent), left(left), right(right)
			{
				
			}

			BST_Node(const value_type &val, BST_Node *parent = u_nullptr, BST_Node *left = u_nullptr, BST_Node *right = u_nullptr)
				: value(val), parent(parent), left(left), right(right)
			{
				
			}

			BST_Node(const BST_Node &nd) : value(nd.value), parent(nd.parent), left(nd.left), right(nd.right)
			{
				
			}

			virtual ~BST_Node()
			{
				
			}

			BST_Node &operator=(const BST_Node &nd)
			{
				if (nd == *this)
					return (*this);

				this->value = nd.value;
				this->parent = nd.parent;
				this->left = nd.left;
				this->right = nd.right;

				return (*this);
			}

			bool operator==(const BST_Node &nd)
			{
				if (value == nd.value)
					return (true);
				return (false);
			}
	};
}

#endif
