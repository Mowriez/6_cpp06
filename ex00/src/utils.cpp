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

#include "utils.hpp"

InputType	checkType(std::string &input) {
	if (isNotANumber(input))
		return FTNAN;
	else if (isInfinite(input))
		return FTINF;
	else if (isChar(input))
		return CHAR;
	else if (!numericalPreCheckValid(input))
		throw InputInvalidException();
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	else if (isInteger(input))
		return INT;
	return UNKNOWN;
}

bool	isNotANumber(std::string &input) {
	if (input == "nanf" || input == "nan")
		return true;
	else
		return false;
}

bool	isInfinite(std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "-inf"
		|| input == "+inf")
		return true;
	else
		return false;
}

bool	numericalPreCheckValid(std::string& input) {
	size_t	periodCounter = 0;
	size_t	fCounter = 0;

	for (size_t it = 0; it < input.length(); it++) {
		if (!isdigit(input[it]) && input[it] != '.' && input[it] != 'f'
			&& input[it] != '+' && input[it] != '-')
			return false;
		if ((input[it] == '+' || input[it] == '-') && it != 0)
			return false;
		if (input[it] == 'f' && it != (input.length() - 1))
			return false;
		if (input[it] == 'f')
			fCounter++;
		if (input[it] == '.')
			periodCounter++;
		if (fCounter > 1 || periodCounter > 1)
			return false;
	}
	return (true);
}

bool	isChar(std::string &input) {
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		return true;
	return false;
}

bool	isFloat(std::string &input) {
	if (input.length() > 2 && input.find('.') != std::string::npos
		&& input.find('f') == input.length() - 1) {
		return true;
		}
	return false;
}

bool	isDouble(std::string &input) {
	if (input.length() > 1 && input.find('.') != std::string::npos
		&& input.find('f') == std::string::npos) {
		return true;
	}
	return false;
}

bool	isInteger(std::string &input) {
	if (input.find('.') == std::string::npos
		&& input.find('f') == std::string::npos) {
		return true;
	}
	return false;
}

void	convertChar(std::string &input) {
	char	c = static_cast<char>(input.c_str()[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convertInt(std::string &input) {
	int		i = static_cast<int>(stoi(input));
	char 	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convertDouble(std::string &input) {
	double	d = static_cast<double>(stod(input));
	int		i = static_cast<int>(d);
	char 	c = static_cast<char>(d);
	float	f = static_cast<float>(d);

	if (floor(d) != d || i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (d > std::numeric_limits<float>::max() || d < d > std::numeric_limits<float>::min())
		std::cout << "float: Impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	convertFloat(std::string &input) {
	float	f = static_cast<float>(stof(input));
	double	d = static_cast<double>(f);
	int		i = static_cast<int>(f);
	char 	c = static_cast<char>(f);

	if (floor(f) != f || i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void		printNotANumber(std::string &input) {
}

void		printInfinity(std::string &input){
}
