/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:42:20 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/04 17:34:29 by rbourgea         ###   ########.fr       */
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

}

#endif