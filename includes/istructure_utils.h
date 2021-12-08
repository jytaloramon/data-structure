/**
 * @author Ytalo Ramon
 * @date   06/12/2021
 */

/**
 * Calculate the offset of the member relative to the type.
 * @param type Struct tag/name.
 * @param member_name Struct member name.
 * @return Offset member.
 */
#define OFFSETMEMBERSTRUCT(type, member_name)                                  \
    ((char *)(&((type *)0)->member_name))

/**
 * Get the starting address of the structure containing the member.
 * @param member_addr Base member address.
 * @param type Struct tag/name.
 * @param member_name Struct member name.
 * @return Starting address of the structure.
 */
#define GETSTRUCTFROM(member_addr, type, member_name)                          \
    ((void *)((char *)(member_addr)-OFFSETMEMBERSTRUCT(type, member_name)))
