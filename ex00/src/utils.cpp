/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:34:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/13 14:34:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.hpp"

InputType	checkType(std::string &input) {
	if (input.length() == 1 && isalpha(input[0]))
		return CHAR;
	if (isSpecialLiteral(input))
		return SPECIAL;
	std::string	newInput = input;
	if (newInput[0] == '-') {
		newInput = newInput.substr(1, newInput.length() - 1);
	}
	if (!preCheckValid(newInput))
		return UNKNOWN;
	if (newInput.length() > 1 && newInput.find('.') != std::string::npos)
	{
		if (newInput[newInput.length() - 1] == 'f'
			&& newInput[newInput.length() - 2] != '.') {
			return FLOAT;
		}
		else if (isdigit(newInput[newInput.length() - 1]))
			return DOUBLE;
	}
	else if (isOnlyNumerical(newInput))
		return INT;
	return UNKNOWN;
}

bool	isOnlyNumerical(std::string& input) {
	for (size_t it = 0; it < input.length(); it++) {
		if (!isdigit(input[it]))
			return (false);
	}
	return (true);
}

bool	preCheckValid(std::string& input) {
	for (size_t it = 0; it < input.length() - 1; it++) {
		if (!isdigit(input[it])) {
			if (input[it]  != '.')
				return (false);
		}
	}
	size_t	periodCount = 0;
	for (size_t it = 0; it < input.length() - 1; it++) {
		if (input[it] == '.') {
			periodCount++;
		}
		if (periodCount > 1)
			return (false);
	}
	return (true);
}

bool	isSpecialLiteral(std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return true;
	else
		return false;
}

void	convertChar(std::string &input) {
	std::cout << "char: '" << static_cast<char>(input.c_str()[0]) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(stoi(input)) << std::endl;
	std::cout << "float: " << static_cast<float>(stof(input)) << std::endl;
	std::cout << "double: " << static_cast<double>(stod(input)) << std::endl;
}

void	convertInt(std::string &input) {
	if (input.length() == 1 && !isprint(input.c_str()[0]))
		std::cout << "char: Non displayable" << std::endl;
	else if (input.length() == 1 && isprint(input.c_str()[0]))
		std::cout << "char: '" << static_cast<char>(input.c_str()[0]) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(stoi(input)) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
	<< static_cast<float>(stof(input)) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(stod(input)) << std::endl;
}
