/* Copyright 2021-2022 by Ian JCV, 'Emil' Williams
 *
 * LainGame is libre software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, under version 3 of the License.
 *
 * LainGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LainGame. If not, see <https://www.gnu.org/licenses/>.
 *
 ************************************************************************
 *
 * File I/O is slow... Loading as a whole... The parser is ment to be
 * multi-layered and expandable, without major regard to speed (threading
 * can be a solution).
 *
 * So maximizing functionality over speed, later on we can put in a fast
 * and hard system -- when we finalize design.
 */

#ifndef PARSE_H_
#define PARSE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

//typedef int (*parse_action_t)(int, char*);

// will open the file as the Extention.
extern int read_whole(char* buffer, const char* filename);
extern void parse_super(char* content);
extern void parse_scene(char* content);
extern void parse_pack(char* content);

#ifdef __cplusplus
}
#endif

#endif /* PARSE_H_ */
