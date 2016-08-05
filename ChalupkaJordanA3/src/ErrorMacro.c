// Jordan Chalupka 0928258
// Macro for error reporter
#define REPORT_ERROR()											\
do { 															\
	fprintf(stderr, "ERROR: %s\n"								\
	"LINE: %d\n"												\
	"FILE: %s\n"												\
	"%s %s\n\n", 												\
	strerror(errno), __LINE__, __FILE__, __TIME__, __DATE__);	\
} while (0);  // Fixed issue with trailing semicollon & else statement
// End of maco for error reporter
