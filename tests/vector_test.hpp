/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:35:52 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/05 14:45:00 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <fstream>
# include <string>

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
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << "[STL] Size = " << stl_vector.size() << std::endl;
	std::cout << "[FT]  Size = " << ft_vector.size() << std::endl;

	if (stl_vector.max_size() == ft_vector.max_size())
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << "[STL] Max Size = " << stl_vector.max_size() << std::endl;
	std::cout << "[FT]  MAx Size = " << ft_vector.max_size() << std::endl;

	if (stl_vector.capacity() == ft_vector.capacity())
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << "[STL] Max Size = " << stl_vector.capacity() << std::endl;
	std::cout << "[FT]  MAx Size = " << ft_vector.capacity() << std::endl;

	if (stl_vector.empty() == ft_vector.empty())
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << "[STL] Max Size = " << stl_vector.empty() << std::endl;
	std::cout << "[FT]  MAx Size = " << ft_vector.empty() << std::endl;

	std::cout << RESET;
}

int main(int argc, char** argv)
{
	std::cout << "VECTOR TESTS: " << std::endl;
	
	std::cout << "Constructors Check: " << std::endl;
	std::vector<int> stl_vector;
	ft::vector<int> ft_vector;

	checkVectorsDiff(stl_vector, ft_vector);

	return (0);
}