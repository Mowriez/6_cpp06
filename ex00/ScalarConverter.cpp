/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:23:36 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/10 16:23:36 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &) {
	std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) {
	std::cout << "ScalarConverter copy assignment operator overload" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter default destructor" << std::endl;
}

void	ScalarConverter::convert(std::string& input) {
	std::cout << "Convert something " << input << std::endl;
}
