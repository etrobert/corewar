int	process_file(char *filename, int champ_id, t_list *champs)
{
	char	*dot;
	t_champion	champ;

	if (ft_strlen(filename) < 4)
	{
		ft_dprintf(2, "Invalid file");
		return (-1);
	}
	if ((dot = ft_strrchr(filename, '.') == NULL)
			return (-1);
	if (ft_strcmp(".cor", dot) != 0)
			return (-1);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	if (champion_init(&champ, 
}

int	process_option(char *cur, t_list *args, t_list_it *it)
{
	char	*tmp;

	if (ft_strcmp("-v", cur) == 0)
	{
		if (ft_list_end(args, *it))
				return (-1);
		ft_list_it_inc(it);
		tmp = (char*)ft_list_it_get(args, *it);
		//because verbose level is 1 to 4 comparing the char directly could be better
		if (ft_str_test_chars(tmp, &ft_isdigit))
		{
			//check if verbose is already set?
			//set verbose level
			ft_atoi(tmp);/get the verbose level
		}
		else
			return (-1);
	}
	else if (ft_strcmp("-n", cur) == 0)
	{
		if (ft_list_end(args, *it))
				return (-1);
		ft_list_it_inc(it);
		tmp = (char*)ft_list_it_get(args, *it);
		ft_list_it_inc(it);
		if (ft_list_end(args, *it))
				return (-1);
		if (ft_str_test_chars(tmp, &ft_isdigit))
		{
			champ_id = ft_atoi(tmp);
			tmp = (char*)ft_list_it_get(args, *it);
			if (process_file(tmp, champ_id) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	else if (ft_strcmp("-dump", cur) == 0)
	{
		if (ft_list_end(args, *it))
				return (-1);
		ft_list_it_inc(it);
		tmp = (char*)ft_list_it_get(args, *it);
		if (ft_str_test_chars(tmp, &ft_isdigit))
		{
			//check if dump cycle is already set?
			//set dump cycle
			dump_cycle = ft_atoi(tmp);
		}
		else
			return (-1);
	}
	else if (ft_strcmp("-g", cur) == 0)
	{
		//enable graphical mode
	}
	else if (ft_strcmp("-h", cur) == 0)
	{
		print_help();
		return (-1);
	}
	else
	{
		if (process_file(cur, -1) == -1)
			return (-1);
	}
	return (0);
}
