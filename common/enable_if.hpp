/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:37:20 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/04 17:32:49 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

namespace ft
{
	// ================================== //
	// enable_if must be reimplemented ✅ //
	// ================================== //
	// https://www.cplusplus.com/reference/type_traits/enable_if/

	template <bool Cond, class T = void>
	struct enable_if
	{
		
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
};

#endif