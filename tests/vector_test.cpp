/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:35:52 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/07 17:30:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <fstream>
# include <cstring>
# include <iostream>

# include "../vector.hpp"

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

template <class T>
void checkVectorsDiff(std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
	if (stl_vector.size() == ft_vector.size())
		std::cout << GREEN << std::endl << "=> size() [OK]" << std::endl;
	else
		std::cout << RED << "size() [ERROR]" << std::endl;
	std::cout << "[STL] Size = " << stl_vector.size() << std::endl;
	std::cout << "[FT]  Size = " << ft_vector.size() << std::endl;

	if (stl_vector.max_size() == ft_vector.max_size())
		std::cout << GREEN << std::endl << "=> max_size() [OK]" << std::endl;
	else
		std::cout << RED << "max_size() [ERROR]" << std::endl;
	std::cout << "[STL] Max Size = " << stl_vector.max_size() << std::endl;
	std::cout << "[FT]  Max Size = " << ft_vector.max_size() << std::endl;

	if (stl_vector.capacity() == ft_vector.capacity())
		std::cout << GREEN << std::endl << "=> capacity() [OK]" << std::endl;
	else
		std::cout << RED << "capacity() [ERROR]" << std::endl;
	std::cout << "[STL] Max Size = " << stl_vector.capacity() << std::endl;
	std::cout << "[FT]  Max Size = " << ft_vector.capacity() << std::endl;

	if (stl_vector.empty() == ft_vector.empty())
		std::cout << GREEN << std::endl << "=> empty() [OK]" << std::endl;
	else
		std::cout << RED << "empty() [ERROR]" << std::endl;
	std::cout << "[STL] Empty = " << stl_vector.empty() << std::endl;
	std::cout << "[FT]  Empty = " << ft_vector.empty() << std::endl << std::endl;
	
	std::cout << RESET << "[STL] Content = [";
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
	std::cout << "]" << std::endl << std::endl;
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	std::cout << BOLD << "VECTOR TESTS: " << RESET << std::endl;
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Default constructor: " << std::endl;
	std::vector<int> stl_vector_int;
	ft::vector<int> ft_vector_int;
	checkVectorsDiff(stl_vector_int, ft_vector_int);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Default constructor pointer: " << std::endl;
	std::vector<int> *stl_vector_int_p = new std::vector<int>;
	ft::vector<int> *ft_vector_int_p = new ft::vector<int>;
	checkVectorsDiff(*stl_vector_int_p, *ft_vector_int_p);
	delete stl_vector_int_p;
	delete ft_vector_int_p;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Fill constructor: " << std::endl;
	std::vector<int> stl_vector_fill(0);
	ft::vector<int> ft_vector_fill(0);
	checkVectorsDiff(stl_vector_fill, ft_vector_fill);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Fill constructor sized: " << std::endl;
	std::vector<int> stl_vector_fill_sized(42);
	ft::vector<int> ft_vector_fill_sized(42);
	checkVectorsDiff(stl_vector_fill_sized, ft_vector_fill_sized);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Fill constructor sized + value: " << std::endl;
	std::vector<int> stl_vector_fill_sizedv(42, 42);
	ft::vector<int> ft_vector_fill_sizedv(42, 42);
	checkVectorsDiff(stl_vector_fill_sizedv, ft_vector_fill_sizedv);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Range constructor: " << std::endl;
	int range_array[] = {42, 21, 123456, 0, 4, 13};
	std::vector<int>::iterator stl_iterator(&(range_array[0]));
	ft::vector<int>::iterator ft_iterator(&(range_array[0]));
	std::vector<int> stl_vector_range(stl_iterator, stl_iterator + 6);
	ft::vector<int> ft_vector_range(ft_iterator, ft_iterator + 6);
	checkVectorsDiff(stl_vector_range, ft_vector_range);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Copy constructor: " << std::endl;
	std::vector<int> stl_vector_copy(stl_vector_range);
	ft::vector<int> ft_vector_copy(ft_vector_range);
	checkVectorsDiff(stl_vector_copy, ft_vector_copy);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Assign constructor: " << std::endl;
	std::vector<int> stl_vector_assign = stl_vector_range;
	ft::vector<int> ft_vector_assign = ft_vector_range;
	checkVectorsDiff(stl_vector_assign, ft_vector_assign);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Iterator begin(): " << std::endl;
	int begin_stl = *(stl_vector_range.begin());
	int begin_ft = *(ft_vector_range.begin());
	if (begin_stl == begin_ft)
		std::cout << GREEN << std::endl << "=> begin() [OK]" << std::endl;
	else
		std::cout << RED << "=> begin() [ERROR]" << std::endl;
	std::cout << "[STL] begin() = " << begin_stl << std::endl;
	std::cout << "[FT]  begin() = " << begin_ft  << std::endl << std::endl;
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Const Iterator begin(): " << std::endl;
	std::vector<int>::const_iterator stl_const_it = stl_vector_range.begin();
	ft::vector<int>::const_iterator ft_const_it = ft_vector_range.begin();
	const int const_begin_stl = *(stl_const_it);
	const int const_begin_ft = *(ft_const_it);
	if (const_begin_stl == const_begin_ft)
		std::cout << GREEN << std::endl << "=> const begin() [OK]" << std::endl;
	else
		std::cout << RED << "=> const begin() [ERROR]" << std::endl;
	std::cout << "[STL] begin() = " << const_begin_stl << std::endl;
	std::cout << "[FT]  begin() = " << const_begin_ft << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Iterator end(): " << std::endl;
	int end_stl = *(stl_vector_range.end() - 1);
	int end_ft = *(ft_vector_range.end() - 1);
	if (end_stl == end_ft)
		std::cout << GREEN << std::endl << "=> end() [OK]" << std::endl;
	else
		std::cout << RED << "=> end() [ERROR]" << std::endl;
	std::cout << "[STL] end() = " << end_stl << std::endl;
	std::cout << "[FT]  end() = " << end_ft << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Const Iterator end(): " << std::endl;
	std::vector<int>::const_iterator stl_const_end = stl_vector_range.end() - 1;
	ft::vector<int>::const_iterator ft_const_end = ft_vector_range.end() - 1;
	const int const_end_stl = *(stl_const_end);
	const int const_end_ft = *(ft_const_end);
	if (const_end_stl == const_end_ft)
		std::cout << GREEN << std::endl << "=> const end() [OK]" << std::endl;
	else
		std::cout << RED << "=> const end() [ERROR]" << std::endl;
	std::cout << "[STL] end() = " << const_end_stl << std::endl;
	std::cout << "[FT]  end() = " << const_end_ft << std::endl << std::endl;
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Iterator rbegin(): " << std::endl;
	int rbegin_stl = *(stl_vector_range.rbegin());
	int rbegin_ft = *(ft_vector_range.rbegin());
	if (rbegin_stl == rbegin_ft)
		std::cout << GREEN << std::endl << "=> rbegin() [OK]" << std::endl;
	else
		std::cout << RED << "=> rbegin() [ERROR]" << std::endl;
	std::cout << "[STL] rbegin() = " << rbegin_stl << std::endl;
	std::cout << "[FT]  rbegin() = " << rbegin_ft << std::endl << std::endl;
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Const Iterator rbegin(): " << std::endl;
	std::vector<int>::const_reverse_iterator stl_const_rbegin = stl_vector_range.rbegin();
	ft::vector<int>::const_reverse_iterator ft_const_rbegin = ft_vector_range.rbegin();
	const int const_rbegin_stl = *(stl_const_rbegin);
	const int const_rbegin_ft = *(ft_const_rbegin);
	if (const_rbegin_stl == const_rbegin_ft)
		std::cout << GREEN << std::endl << "=> const rbegin() [OK]" << std::endl;
	else
		std::cout << RED << "=> const rbegin() [ERROR]" << std::endl;
	std::cout << "[STL] rbegin() = " << const_rbegin_stl << std::endl;
	std::cout << "[FT]  rbegin() = " << const_rbegin_ft << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Iterator rend(): " << std::endl;
	int rend_stl = *(stl_vector_range.rend() - 1);
	int rend_ft = *(ft_vector_range.rend() - 1);
	if (rend_stl == rend_ft)
		std::cout << GREEN << std::endl << "=> rend() [OK]" << std::endl;
	else
		std::cout << RED << "=> rend() [ERROR]" << std::endl;
	std::cout << "[STL] rend() = " << rend_stl << std::endl;
	std::cout << "[FT]  rend() = " << rend_ft << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Const Iterator rend(): " << std::endl;
	std::vector<int>::const_reverse_iterator stl_const_rend = stl_vector_range.rend() - 1;
	ft::vector<int>::const_reverse_iterator ft_const_rend = ft_vector_range.rend() - 1;
	const int const_rend_stl = *(stl_const_rend);
	const int const_rend_ft = *(ft_const_rend);
	if (const_rend_stl == const_rend_ft)
		std::cout << GREEN << std::endl << "=> const rend() [OK]" << std::endl;
	else
		std::cout << RED << "=> const rend() [ERROR]" << std::endl;
	std::cout << "[STL] rend() = " << const_rend_stl << std::endl;
	std::cout << "[FT]  rend() = " << const_rend_ft << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Size small: " << std::endl;
	std::vector<int> stl_fill(21);
	ft::vector<int> ft_fill(21);
	checkVectorsDiff(stl_fill, ft_fill);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Size big: " << std::endl;
	std::vector<int> stl_fill2(100042);
	ft::vector<int> ft_fill2(100042);
	checkVectorsDiff(stl_fill2, ft_fill2);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Resize +++: " << std::endl;
	std::vector<int> stl_fill3(42);
	ft::vector<int> ft_fill3(42);
	stl_fill3.resize(84);
	ft_fill3.resize(84);
	checkVectorsDiff(stl_fill3, ft_fill3);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Resize ---: " << std::endl;
	std::vector<int> stl_fill4(42);
	ft::vector<int> ft_fill4(42);
	stl_fill4.resize(21);
	ft_fill4.resize(21);
	checkVectorsDiff(stl_fill4, ft_fill4);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Capacity small: " << std::endl;
	std::vector<int> stl_fill5(42);
	ft::vector<int> ft_fill5(42);
	stl_fill5.push_back(21);
	ft_fill5.push_back(21);
	stl_fill5.push_back(84);
	ft_fill5.push_back(84);
	checkVectorsDiff(stl_fill5, ft_fill5);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Capacity big: " << std::endl;
	std::vector<int> stl_fill6(42000);
	ft::vector<int> ft_fill6(42000);
	checkVectorsDiff(stl_fill6, ft_fill6);
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Reserve: " << std::endl;
	std::vector<int> stl_reserve;
	ft::vector<int> ft_reserve;
	stl_reserve.reserve(42);
	ft_reserve.reserve(42);
	checkVectorsDiff(stl_reserve, ft_reserve);
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "Operator[]: " << std::endl;
	if (stl_vector_range[0] == ft_vector_range[0])
		std::cout << GREEN << std::endl << "=> operator[0] [OK]" << std::endl;
	else
		std::cout << RED << "=> operator[0] [ERROR]" << std::endl;
	std::cout << "[STL] operator[0] = " << stl_vector_range[0] << std::endl;
	std::cout << "[FT]  operator[0] = " << ft_vector_range[0] << std::endl << std::endl;
	std::cin.get();

	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "at(4): " << std::endl;
	if (stl_vector_range.at(4) == ft_vector_range.at(4))
		std::cout << GREEN << std::endl << "=> at(4) [OK]" << std::endl;
	else
		std::cout << RED << "=> a(4) [ERROR]" << std::endl;
	std::cout << "[STL] at(4) = " << stl_vector_range.at(4) << std::endl;
	std::cout << "[FT]  at(4) = " << ft_vector_range.at(4) << std::endl << std::endl;
	std::cin.get();
	
	std::cout << BOLD << "==============================" << RESET << std::endl;
	std::cout << std::endl << "const at(4): " << std::endl;
	const int stl_at_const = stl_vector_range.at(4);
	const int ft_at_const = ft_vector_range.at(4);
	if (stl_at_const == ft_at_const)
		std::cout << GREEN << std::endl << "=> const at(4) [OK]" << std::endl;
	else
		std::cout << RED << "=> const a(4) [ERROR]" << std::endl;
	std::cout << "[STL] const at(4) = " << stl_at_const << std::endl;
	std::cout << "[FT]  const at(4) = " << ft_at_const << std::endl << std::endl;
	std::cin.get();



	return (0);
}