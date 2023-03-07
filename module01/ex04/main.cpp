/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:15:07 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/07 17:51:12 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		buffer;
	size_t			pos;

	if (argc != 4)
	{
		std::cout << "Invalid argument" << std::endl;
		std::cout << "Follow this format: [program] [filename] [string1] [string2]" << std::endl;
		return 1;
	}

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	infile.open(filename);
	if (infile.is_open() == false)
	{
		std::cout << "Failed to open " << filename << std::endl;
		return 1;
	}

	outfile.open(filename + ".replace");
	if (outfile.is_open() == false)
	{
		std::cout << "Failed to open " << filename << ".replace" << std::endl;
		return 1;
	}

	std::getline(infile, buffer, '\0');
	pos = 0;
	while (1)
	{
		pos = buffer.find(s1, pos);
		if (pos == std::string::npos)
			break ;
		buffer.erase(pos, s1.size());
		buffer.insert(pos, s2);
		pos += s2.size();
	}

	outfile << buffer;

	infile.close();
	outfile.close();
	
	return 0;
}
