#ifndef COMMAND_H_
#define COMMAND_H_

#include <serializer/serialization.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    /** Command ID */
    uint8_t index;
    /** The function to execute when the index match. It takes argument count
     * and a MessagePack context as argument. */
    void (*f)(int, cmp_ctx_t *);
} command_t;

/** Parses a datagram data field and executes the correct function.
 * @param [in] data The raw data to parse.
 * @param [in] commands A list of all possible commands.
 * @param [in] command_len Length of the commands array.
 */
void protocol_execute_command(char *data, command_t *commands, int command_len);

#ifdef __cplusplus
}
#endif


#endif
