/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:31:55 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/12 13:57:39 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <map>
# include <fstream>
# include <cstring>
# include <iostream>

# include "../map.hpp"

// Mac Colors
// # define RESET "\033[0m"
// # define BOLD "\033[1m"
// # define RED "\033[31m"
// # define GREEN "\033[32m"
// # define BLUE "\033[34m"
// # define PINK "\033[35m"

// Linux Colors
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define BLUE "\e[34m"
# define PINK "\e[35m"


template <class T1, class T2>
void checkMapsDiff(std::map<T1, T2>& stl_map, ft::map<T1, T2>& ft_map)
{
	if (stl_map.size() == ft_map.size())
		std::cout << GREEN << std::endl << "=> size() [OK]" << std::endl;
	else
		std::cout << RED << "size() [ERROR]" << std::endl;
	std::cout << "[STL] Size = " << stl_map.size() << std::endl;
	std::cout << "[FT]  Size = " << ft_map.size() << std::endl;

	if (stl_map.max_size() == ft_map.max_size())
		std::cout << GREEN << std::endl << "=> max_size() [OK]" << std::endl;
	else
		std::cout << RED << "max_size() [ERROR]" << std::endl;
	std::cout << "[STL] Max Size = " << stl_map.max_size() << std::endl;
	std::cout << "[FT]  Max Size = " << ft_map.max_size() << std::endl;

	if (stl_map.empty() == ft_map.empty())
		std::cout << GREEN << std::endl << "=> empty() [OK]" << std::endl;
	else
		std::cout << RED << "empty() [ERROR]" << std::endl;
	std::cout << "[STL] Empty = " << stl_map.empty() << std::endl;
	std::cout << "[FT]  Empty = " << ft_map.empty() << std::endl << std::endl;
	
	std::cout << RESET << "[STL] Content = [";
	typename std::map<T1, T2>::const_iterator stl_it;
	for (stl_it = stl_map.begin(); stl_it != stl_map.end(); stl_it++)
	{
		std::cout << "{" << (*stl_it).first << ", " << (*stl_it).second << "}, ";
	}
	std::cout << "]" << std::endl;
	std::cout << "[FT]  Content = [";
	typename ft::map<T1, T2>::const_iterator ft_it;
	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
	{
		std::cout << "{" << (*ft_it).first << ", " << (*ft_it).second << "}, ";
	}
	std::cout << "]" << std::endl << std::endl;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::cout << BOLD << "MAP TESTS: " << RESET << std::endl;

	std::cout << BOLD << "==============================" << std::endl;
	std::cout << std::endl << "Default constructor: " << RESET << std::endl;
	std::map<int, std::string> stl_default_map;
	ft::map<int, std::string> ft_default_map;
	checkMapsDiff(stl_default_map, ft_default_map);
	std::cin.get();


}