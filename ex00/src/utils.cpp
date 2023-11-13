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
	std::string	newInput = input;
	if (newInput[0] == '-') {
		newInput = newInput.substr(1, newInput.length() - 1);
	}
	if (!preCheckValid(newInput))
		return UNKNOWN;
	if (newInput.length() > 1)
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
