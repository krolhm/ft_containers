/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:35:52 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/06 20:23:43 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <fstream>
# include <cstring>
# include <iostream>


# include "../vector.hpp"

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define PINK "\033[35m"

template <class T>
void checkVectorsDiff(std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
	if (stl_vector.size() == ft_vector.size())
		std::cout << std::endl << "=> size() [OK]" << std::endl;
	else
		std::cout << "size() [ERROR]" << std::endl;
	std::cout << "[STL] Size = " << stl_vector.size() << std::endl;
	std::cout << "[FT]  Size = " << ft_vector.size() << std::endl;

	if (stl_vector.max_size() == ft_vector.max_size())
		std::cout << std::endl << "=> max_size() [OK]" << std::endl;
	else
		std::cout << "max_size() [ERROR]" << std::endl;
	std::cout << "[STL] Max Size = " << stl_vector.max_size() << std::endl;
	std::cout << "[FT]  Max Size = " << ft_vector.max_size() << std::endl;

	if (stl_vector.capacity() == ft_vector.capacity())
		std::cout << std::endl << "=> capacity() [OK]" << std::endl;
	else
		std::cout << "capacity() [ERROR]" << std::endl;
	std::cout << "[STL] Max Size = " << stl_vector.capacity() << std::endl;
	std::cout << "[FT]  Max Size = " << ft_vector.capacity() << std::endl;

	if (stl_vector.empty() == ft_vector.empty())
		std::cout << std::endl << "=> empty() [OK]" << std::endl;
	else
		std::cout << "empty() [ERROR]" << std::endl;
	std::cout << "[STL] Empty = " << stl_vector.empty() << std::endl;
	std::cout << "[FT]  Empty = " << ft_vector.empty() << std::endl << std::endl;
	
	std::cout << "[STL] Content = [";
	typename std::vector<T>::const_iterator stl_it;
	for (stl_it = stl_vector.begin(); stl_it != stl_vector.end(); stl_it++)
	{
		std::cout << *stl_it;
		if (stl_it + 1 != stl_vector.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "[FT]  Content = [";
	typename ft::vector<T>::const_iterator ft_it;
	for (ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
	{
		std::cout << *ft_it;
		if (ft_it + 1 != ft_vector.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	std::cout << "VECTOR TESTS: " << std::endl;
	
	std::cout << "Constructors Check: " << std::endl;
	
	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Default constructor: " << std::endl;
	std::vector<int> stl_vector_int;
	ft::vector<int> ft_vector_int;
	checkVectorsDiff(stl_vector_int, ft_vector_int);
	
	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Default constructor pointer: " << std::endl;
	std::vector<int> *stl_vector_int_p = new std::vector<int>;
	ft::vector<int> *ft_vector_int_p = new ft::vector<int>;
	checkVectorsDiff(*stl_vector_int_p, *ft_vector_int_p);
	delete stl_vector_int_p;
	delete ft_vector_int_p;

	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Fill constructor: " << std::endl;
	std::vector<char> stl_vector_fill(0);
	ft::vector<char> ft_vector_fill(0);
	checkVectorsDiff(stl_vector_fill, ft_vector_fill);
	
	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Fill constructor sized: " << std::endl;
	std::vector<char> stl_vector_fill_sized(42);
	ft::vector<char> ft_vector_fill_sized(42);
	checkVectorsDiff(stl_vector_fill_sized, ft_vector_fill_sized);
	
	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Fill constructor sized + value: " << std::endl;
	std::vector<char> stl_vector_fill_sizedv(42, 42);
	ft::vector<char> ft_vector_fill_sizedv(42, 42);
	checkVectorsDiff(stl_vector_fill_sizedv, ft_vector_fill_sizedv);
	
	std::cout << "==============================" << std::endl;
	std::cout << std::endl << "Range constructor: " << std::endl;
	int range_array[] = {42, 21, 123456, 0, 4, 13};
	std::vector<int>::iterator stl_iterator(&(range_array[0]));
	ft::vector<int>::iterator ft_iterator(&(range_array[0]));
	std::vector<char> stl_vector_range(stl_iterator, stl_iterator + 6);
	ft::vector<char> ft_vector_range(ft_iterator, ft_iterator + 6);
	checkVectorsDiff(stl_vector_range, ft_vector_range);

	return (0);
}