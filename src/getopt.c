#include <ft/getopt.h>
#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int ft_optind = 0, ft_opterr = 0, ft_optopt = 0;
char *ft_optarg = NULL;

static int ft_optchar = 0;

__attribute__((format(printf, 2, 3))) static void
print_error(const char *progname, const char *restrict fmt, ...)
{
	va_list list;
	va_start(list, fmt);

	if (progname)
		fprintf(stderr, "%s: ", progname);
	vfprintf(stderr, fmt, list);
	va_end(list);
}

static int do_getopt_long(int argc, char **argv, const char *optstring,
			  const struct option *longopts, int *longindex)
{
	(void)argc;
	int colon = optstring[0] == ':';

	char *cur = argv[ft_optind++] + 2;

	if (!*cur)
		return -1;

	int cnt = 0, match;
	char *arg;
	for (size_t i = 0; longopts[i].name; ++i) {
		const char *optname = longopts[i].name;
		char *start = cur;

		while (*start && *start != '=' && *optname == *start) {
			++optname;
			++start;
		}

		if (*start && *start != '=')
			continue;

		match = i;
		arg = start;
		if (!*optname) {
			cnt = 1;
			break;
		}
		++cnt;
	}

	if (cnt == 1) {
		const struct option *opt = &longopts[match];
		if (*arg == '=') {
			if (!opt->has_arg) {
				ft_optopt = opt->val;
				if (!colon && ft_opterr)
					print_error(
						argv[0],
						"option '--%s' doesn't allow an argument\n",
						opt->name);
				return '?';
			}
			ft_optarg = arg + 1;
		} else if (opt->has_arg == required_argument) {
			if (!(ft_optarg = argv[ft_optind])) {
				ft_optopt = opt->val;
				if (colon)
					return ':';
				if (ft_opterr)
					print_error(
						argv[0],
						"option '--%s' requires an argument\n",
						opt->name);
				return '?';
			}
			++ft_optind;
		}
		if (longindex)
			*longindex = match;

		if (opt->flag) {
			*opt->flag = opt->val;
			return 0;
		}
		return opt->val;
	}

	if (!colon && ft_opterr) {
		if (cnt > 1)
			print_error(argv[0], "option '%s' is ambigious\n", cur);
		else
			print_error(argv[0], "unrecognized option: '%s'\n",
				    cur);
	}
	return '?';
}

static void permute(char **argv, size_t dest, size_t src)
{
	char *tmp = argv[src];
	for (; dest != src; --src) {
		argv[src] = argv[src - 1];
	}
	argv[dest] = tmp;
}

static int do_getopt_short(int argc, char **argv, const char *optstring)
{
	int colon = optstring[0] == ':';
	if (colon)
		++optstring;

	if (!strcmp(argv[ft_optind], "--")) {
		++ft_optind;
		return -1;
	}

	char *cur = argv[ft_optind];
	int opt = cur[ft_optchar++];
	const char *pos = strchr(optstring, opt);

	if (!pos) {
		ft_optopt = opt;
		if (!colon && ft_opterr) {
			print_error(argv[0], "invalid option -- '%c'\n",
				    ft_optopt);
		}
		return '?';
	}

	if (pos[1] == ':') {
		if (cur[ft_optchar]) {
			ft_optarg = &cur[ft_optchar];
			++ft_optind;
			ft_optchar = 1;
		} else if (ft_optind + 1 < argc) {
			ft_optarg = argv[ft_optind + 1];
			ft_optind += 2;
			ft_optchar = 1;
		} else {
			ft_optopt = opt;
			if (colon)
				return ':';
			if (ft_opterr)
				print_error(
					argv[0],
					"option requires an argument -- '%c'\n",
					ft_optopt);
			return '?';
		}
	}
	return opt;
}

static int do_getopt_common(int argc, char **argv, const char *optstring,
			    const struct option *longopts, int *longindex)
{
	if (!ft_optind) {
		ft_optind = 1;
		ft_optchar = 1;
	}

	if (ft_optind >= argc || !argv[ft_optind])
		return -1;

	int saved = ft_optind;
	int tmp = ft_optind;
	while (!argv[tmp] || argv[tmp][0] != '-') {
		if (!argv[tmp])
			return -1;
		++tmp;
	}
	int resumed = ft_optind = tmp;

	int res;
	if (ft_optchar == 1 && longopts && argv[ft_optind][1] == '-') {
		res = do_getopt_long(argc, argv, optstring, longopts,
				     longindex);
	} else {
		res = do_getopt_short(argc, argv, optstring);

		if (ft_optchar && argv[ft_optind] &&
		    !argv[ft_optind][ft_optchar]) {
			ft_optchar = 1;
			++ft_optind;
		}
	}

	if (resumed > saved) {
		for (int i = ft_optind - resumed; i > 0; --i)
			permute(argv, saved, ft_optind - 1);
		ft_optind -= resumed - saved;
	}
	return res;
}

int ft_getopt(int argc, char **argv, const char *optstring)
{
	return do_getopt_common(argc, argv, optstring, NULL, NULL);
}

int ft_getopt_long(int argc, char **argv, const char *optstring,
		   const struct option *longopts, int *longindex)
{
	return do_getopt_common(argc, argv, optstring, longopts, longindex);
}
