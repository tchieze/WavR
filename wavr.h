/* wavr.h
 * Declares argument struct and all argument
 * handling functions.
 * Created: 14 January 2016
 */

#ifndef __WAVR_H__
#define __WAVR_H__

#include "wav.h"

#define DEFAULT_SAMPLE_RATE 41000
#define DEFAULT_SIGNAL_FREQUENCY 1000.0f
#define DEFAULT_SIGNAL_DURATION 1.0f
#define DEFAULT_OUTFILE "wavrgen.wav"

enum input_method {
	INPUT_NONE, /* => sample generation */
	INPUT_STDIN,
	INPUT_FILE
};

struct wavr_args {
	char *in_filename;
	char *out_filename;
	int sample_dump;
	int thread_count;
	enum input_method input;
	struct signal_spec *sigspec;
	/* TODO make type more explicit here */
	void *generator; /* generator function (actually void (*generator) (struct sample *) */
};

void usage(const char *cmd);
void help(const char *cmd);
void handle_args(struct wavr_args *args, int argc, char *argv[]);


#endif /* __WAVR_H__ */

