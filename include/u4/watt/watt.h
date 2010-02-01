/* include/watt/watt.h
**
** This file is in the public domain.
*/
  /** Noun types.
  **/
    /* u4_path: tuple of term
    ** u4_site: list of term 
    ** u4_tube: atomic document
    ** u4_bowl: tab (term sack)
    ** u4_sack: [tube] or [tube bowl]
    */
      typedef u4_noun u4_path;
      typedef u4_noun u4_site;
      typedef u4_noun u4_tube;
      typedef u4_noun u4_bowl;
      typedef u4_noun u4_sack;

  /** Functions.
  **/
    /* u4_watt_parse(): 
    **
    **   At (pif), convert (zar) to a gene.
    */
      u4_noun
      u4_watt_parse(u4_lane lane,
                    u4_site pif,
                    u4_sack zar);

    /* u4_vere_parse(): 
    **
    **   Convert (mez) to a vere command.
    */
      u4_noun
      u4_vere_parse(u4_lane lane,
                    u4_atom mez);

    /* u4_hume_parse(): 
    **
    **   Convert (mez) to a data noun.
    */
    u4_noun
    u4_hume_parse(u4_lane lane,
                  u4_atom mez);
