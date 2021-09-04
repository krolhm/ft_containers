/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:41:54 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/04 17:32:56 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <cstddef>
#include <limits>
#include <sstream>
#include <typeinfo>
#include <iostream>

namespace ft
{
	// ==================================== //
	// is_integral must be reimplemented ✅ //
	// ==================================== //
	// https://www.cplusplus.com/reference/type_traits/is_integral/

	template <bool is_integral, typename T>
	struct is_integral_res
	{
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral_type : public is_integral_res<false, bool>
	{
		
	};

	template <> // bool
	struct is_integral_type<bool> : public is_integral_res<true, bool>
	{
		
	};

	template <> // char
	struct is_integral_type<char> : public is_integral_res<true, char>
	{
		
	};

	// char16_t & char32_t ???

	template <> // signed char
	struct is_integral_type<signed char> : public is_integral_res<true, signed char>
	{
		
	};

	template <> // short int
	struct is_integral_type<short int> : public is_integral_res<true, short int>
	{
		
	};

	template <> // int
	struct is_integral_type<int> : public is_integral_res<true, int>
	{
		
	};

	template <> // long int
	struct is_integral_type<long int> : public is_integral_res<true, long int>
	{
		
	};

	template <> // long long int
	struct is_integral_type<long long int> : public is_integral_res<true, long long int>
	{
		
	};

	template <> // unsigned char
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char>
	{
		
	};

	template <> // unsigned short int
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int>
	{
		
	};

	template <> // unsigned int
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int>
	{
		
	};

	template <> // unsigned long int
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int>
	{
		
	};

	template <> // unsigned long long int
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int>
	{
		
	};

	template <typename T>
	struct is_integral : public is_integral_type<T>
	{
		// Trait class that identifies whether T is an integral type.
	};
};

#endif