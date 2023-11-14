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

#include "../inc/ScalarConverter.hpp"

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
	InputType	inputType = checkType(input);

	switch(inputType) {
		case CHAR:
			convertChar(input);
			break;
		case INT:
			convertInt(input);
			break;
		case FLOAT:
			std::cout << "Input is a FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Input is a DOUBLE" << std::endl;
			break;
		case SPECIAL:
			std::cout << "Input is SPECIAL" << std::endl;
		case UNKNOWN:
			std::cout << "Input is unknown." << std::endl;
			break;
		default:
			break;
	}
}
