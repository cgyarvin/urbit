/* include/v/vere.h
**
** This file is in the public domain.
*/
  void TermTest(void);    //  entirely temporary!

  /** Quasi-tunable parameters.
  **/
    /* First kernel this executable can boot.
    */
#     define FirstKernel   194
#     define DefaultKernel 192
 
#define RECK

  /** Data types.
  **/
    struct _u2_http;

    /* u2_hhed: http header.
    */
      typedef struct _u2_hhed {
        struct _u2_hhed* nex_u;
        c3_c*            nam_c;
        c3_c*            val_c;
      } u2_hhed;

    /* u2_hbod: http body block.  Also used for responses.
    */
      typedef struct _u2_hbod {
        struct _u2_hbod* nex_u; 
        c3_w             len_w;
        c3_y             hun_y[0];
      } u2_hbod;

    /* u2_hrat: http parser state.
    */
      typedef enum {
        u2_hreq_non,                    
        u2_hreq_nam,
        u2_hreq_val
      } u2_hrat;

    /* u2_hmet: http method.  Matches jhttp encoding.
    */
      typedef enum {
        u2_hmet_delete,
        u2_hmet_get,
        u2_hmet_head,
        u2_hmet_post,
        u2_hmet_put,
        u2_hmet_other                       //  ie, unsupported
      } u2_hmet;
 
    /* u2_hreq: http request.
    */
      typedef struct _u2_hreq {
        struct _u2_hcon* hon_u;             //  connection
        c3_w             seq_l;             //  sequence within connection
        u2_hmet          met_e;             //  method
        u2_hrat          rat_e;             //  parser state
        void*            par_u;             //  struct http_parser *
        c3_c*            url_c;             //  url
        u2_bean          liv;               //  keepalive
        u2_bean          end;               //  all responses added
        u2_hhed*         hed_u;             //  headers 
        u2_hbod*         bod_u;             //  body parts
        struct _u2_hreq* nex_u;             //  next in request queue
        u2_hbod*         rub_u;             //  exit of write queue
        u2_hbod*         bur_u;             //  entry of write queue
      } u2_hreq;

    /* u2_hrep: simple http response.
    */
      typedef struct _u2_hrep {
        c3_w             coq_l;             //  connection number
        c3_w             seq_l;             //  request number
        c3_w             sas_w;             //  status
        u2_hhed*         hed_u;             //  headers
        u2_hbod*         bod_u;             //  body (one part)
      } u2_hrep;

    /* u2_hcon: http connection.
    */
      typedef struct _u2_hcon {
        struct ev_io     wax_u;             //  event handler state
        u2_bean          nuw;               //  if true, needs init
        u2_bean          ded;               //  if true, needs cleanup
        c3_w             coq_l;             //  connection number
        c3_w             seq_l;             //  next request number
        struct _u2_http* htp_u;             //  backlink to server 
        struct _u2_hcon* nex_u;             //  next in server's list
        struct _u2_hreq* ruc_u;             //  request under construction
        struct _u2_hreq* req_u;             //  exit of request queue
        struct _u2_hreq* qer_u;             //  entry of request queue
      } u2_hcon;

    /* u2_http: http server.
    */
      typedef struct _u2_http {
        struct ev_io     wax_u;             //  event handler state
        u2_bean          nuw;               //  if true, needs init
        u2_bean          ded;               //  if true, needs cleanup
        c3_w             sev_l;             //  server number
        c3_w             coq_l;             //  next connection number
        c3_w             por_w;             //  running port
        struct _u2_hcon* hon_u;             //  connection list
        struct _u2_http* nex_u;             //  next in list
      } u2_http;

    /* u2_apac: ames packet, coming or going.
    */
      typedef struct _u2_apac {
        struct _u2_apac* nex_u;             //  next in queue
        c3_w             pip_w;             //  IPv4 address, to
        c3_s             por_s;             //  IPv4 port, to
        c3_w             len_w;             //  length in bytes
        c3_y             hun_y[0];          //  data
      } u2_apac;

    /* u2_ames: ames networking.
    */
      typedef struct _u2_ames {             //  packet network state
        struct ev_io    wax_u;              //  event handler state
        struct ev_timer tim_u;              //  network timer
        u2_bean         alm;                //  alarm on
        c3_w            pip_w;              //  public IPv4 address
        c3_s            por_s;              //  public IPv4 port
        u2_apac*        out_u;              //  exit of output queue
        u2_apac*        tou_u;              //  entry of output queue
      } u2_ames;

    /* u2_ubuf: unix tty i/o buffer.
    */
      typedef struct _u2_ubuf {
        struct _u2_ubuf* nex_u; 
        c3_w             len_w;
        c3_y             hun_y[0];          //  bytes to send
      } u2_ubuf;

    /* u2_utat: unix terminal state.
    */
      typedef struct {
        struct {
          c3_w* lin_w;                      //  current line (utf32)
          c3_w  len_w;                      //  length of current line
          c3_w  cus_w;                      //  cursor position
        } mir;

        struct {                            //  escape code control
          u2_bean ape;                      //  escape received 
          u2_bean bra;                      //  bracket or O received
        } esc;

        struct {
          c3_y syb_y[5];                    //  utf8 code buffer
          c3_w len_w;                       //  present length
          c3_w wid_w;                       //  total width
        } fut;
      } u2_utat;

    /* u2_uled: event log header.
    */
      typedef struct {
        c3_l mag_l;                         //  mug of log format, 'a', 'b'...
        c3_w kno_w;                         //  kernel number validated with
        c3_l key_l;                         //  mug of crypto key, or 0
        c3_l sev_l;                         //  host process identity
        c3_l tno_l;                         //  terminal count in host
      } u2_uled;

    /* u2_ular: event log trailer.
    */
      typedef struct {
        c3_w syn_w;                         //  must equal mug of address
        c3_w ent_w;                         //  event sequence number
        c3_w len_w;                         //  word length of this event
        c3_w mug_w;                         //  mug of noun
      } u2_ular;

    /* u2_ulog: unix event log.
    */
      typedef struct {
        c3_i fid_i;                         //  file descriptor
        c3_w ent_w;                         //  event sequence number
        c3_w len_w;                         //  length in words
      } u2_ulog;

    /* u2_utfo: unix terminfo strings.
    */
      typedef struct {
        struct {
          const c3_y* kcuu1_y;              //  key_up
          const c3_y* kcud1_y;              //  key_down    
          const c3_y* kcub1_y;              //  key_back
          const c3_y* kcuf1_y;              //  key_forward
          c3_w        max_w;                //  maximum input sequence length
        } inn;
        struct {
          const c3_y* clear_y;              //  clear_screen
          const c3_y* el_y;                 //  clr_bol clear to beginning 
          const c3_y* el1_y;                //  clr_eol clear to end
          const c3_y* bel_y;                //  bel sound bell
          const c3_y* cub1_y;               //  parm_left
          const c3_y* cuf1_y;               //  parm_right
          const c3_y* cub_y;                //  parm_left_cursor #num
          const c3_y* cuf_y;                //  parm_right_cursor #num 
        } out;
      } u2_utfo;

#if 0
    /* u2_uwen: unix alarm.
    */
      typedef struct _u2_uwen {
        c3_y* pax_y;                        //  printed path
        c3_d  wen_d[2];                     //  timer expire
      };

    /* u2_utim: unix timer control.
    */
      typedef struct _u2_utim {
        struct ev_timer wat_u;              //  libev timer control
        u2_uwen*        wen_u;              //  timers in ascending order
      };
#endif

    /* u2_utty: unix tty.
    */
      typedef struct _u2_utty {
        struct ev_io     wax_u;             //  event handler state
        struct termios   bak_u;             //  cooked terminal state
        struct termios   raw_u;             //  raw terminal state
        c3_i             cug_i;             //  blocking fcntl flags
        c3_i             nob_i;             //  nonblocking fcntl flags
        c3_w             tid_l;             //  terminal identity number
        u2_utfo          ufo_u;             //  terminfo strings
        u2_utat          tat_u;             //  control state
        u2_ubuf*         out_u;             //  exit of output queue
        u2_ubuf*         tou_u;             //  entry of output queue
        struct _u2_utty* nex_u;             //  next in host list
      } u2_utty;

    /* u2_steg: kernel stage.
    */
      typedef struct {
        c3_m    mod_m;                      //  stage mode, or 0 for none
        u2_noun ken;                        //  stable kernel, or 0 for none
        u2_noun ras;                        //  transition kernel, or 0
        u2_noun tip;                        //  broken sub-kernel, or 0
        u2_noun tul;                        //  toolkit map - [term vase]

        struct {
          u2_noun seed;                     //  kernel vase
          u2_noun what;                     //  platform vase
          u2_noun ream;                     //  text to gene 
          u2_noun rain;                     //  text, path to gene 
          u2_noun sell;                     //  vase to tank
          u2_noun skol;                     //  type to tank
          u2_noun slot;                     //  vase fragment
          u2_noun slam;                     //  nock vase call - [vase vase]
          u2_noun slap;                     //  nock vase pipe - [vase gene]
          u2_noun slop;                     //  nock vase pair - [vase vase]
          u2_noun scot;                     //  coin printer
        } toy;

        struct {
          u2_noun old;                      //  legacy app (gunn) - pre 221
        } dev;

        struct {
          u2_noun vax;                      //  reck vase
          c3_c*   who_c;                    //  name prefix
        } rec;

        struct {
          struct {                          //  packet pile
            u2_noun log;                    //  packets
            u2_noun len;                    //  (lent log)
            u2_noun sol;                    //  vase of cato core
          } pyl;
        } has;
      } u2_steg;

    /* u2_reck: modern reck structure.
    */
      struct _u2_host; 
      struct _u2_cart;
      typedef struct {
        c3_w    kno_w;                    //  kernel stage
        c3_w    rno_w;                    //  rotor index (always 0)

        struct {
          struct _u2_cart* egg_u;         //  exit of ovum queue
          struct _u2_cart* geg_u;         //  entry of ovum queue
        } ova;

        struct {                          //  function gates, use mung
          u2_noun duel;                   //  compare resource trees
          u2_noun rain;                   //  parse path, text -> gene
          u2_noun ream;                   //  parse text -> gene
          u2_noun slam;                   //  call ([vase vase] -> vase)
          u2_noun sham;                   //  SHA-256 on noun
          u2_noun shed;                   //  ghetto decrypt
          u2_noun shen;                   //  ghetto encrypt
          u2_noun slap;                   //  layer ([vase gene] -> vase)
          u2_noun slop;                   //  cell ([vase vase] -> vase)
          u2_noun slay;                   //  text to coin
          u2_noun scot;                   //  mole to text
          u2_noun spat;                   //  path to text
          u2_noun stab;                   //  text to path
          u2_noun turf;                   //  utf8 to utf32
          u2_noun tuft;                   //  utf32 to utf8
          u2_noun mook;                   //  trace conversion
          u2_noun wash;                   //  tank window printer
        } toy;

        u2_noun now;                      //  current time, as noun
        u2_noun wen;                      //  current time, as text
        u2_noun sev_l;                    //  instance number
        u2_noun sen;                      //  instance string
        u2_noun own;                      //  owner list

        c3_c* dir_c;                      //  full path to ship
        u2_noun our;                      //  main owner
        u2_noun pod;                      //  owner as string
        u2_noun roe;                      //  temporary unsaved events
        u2_noun key;                      //  log key, or 0

        u2_noun ken;                      //  kernel formula
        u2_noun syd;                      //  kernel seed 
        u2_noun roc;                      //  rotor core
      } u2_reck;

 
    /* u2_cart: ovum carton.
    */
      typedef struct _u2_cart {
        u2_noun egg;                      //  ovum itself
        void (*clr_f)                     //  ovum processing failed
            (u2_reck *rec_u,              //  system
             u2_noun,                     //  egg itself
             u2_noun,                     //  failure mode
             u2_noun);                    //  trace if any
        struct _u2_cart* nex_u;           //  next in queue
      } u2_cart;

    /* u2_host: entire host.
    */
      typedef struct _u2_host {
        u2_wire wir_r;                      //  noun system, 1 per thread
        c3_c*   fel_c;                      //  readline filename
        u2_noun pet;                        //  petname of self, atomic
        u2_noun pat;                        //  unix path to self, atomic
        u2_noun map;                        //  unix arguments as map
        u2_steg ver_e[257];                 //  stages improving downward
        c3_w    kno_w;                      //  current executing stage

        c3_d    now_d;                      //  event tick
        struct ev_loop *lup_u;              //  libev event loop
        u2_http* htp_u;                     //  http servers
        u2_utty* uty_u;                     //  terminal servers
        u2_ulog  lug_u;                     //  event log
        u2_ames  sam_u;                     //  packet interface

        u2_reck rec_u[1];                   //  rotors (hardcoded to 1)
      } u2_host;                            //  host == computer == process

    /* u2_funk: standard system function.
    */
      typedef u2_noun (*u2_funk)(u2_reck* rec_u, u2_noun);

  /** Global variables.
  **/
    c3_global  u2_host  u2_Host;
    c3_global  u2_wire  u2_Wire;
    c3_global  c3_c*    u2_Local;
    c3_global  c3_c*    u2_System;

    c3_global  u2_bean  u2_Flag_Abort;
    c3_global  u2_bean  u2_Flag_Garbage;
    c3_global  u2_bean  u2_Flag_Profile;
    c3_global  u2_bean  u2_Flag_Verbose;

#   define u2_ve_at() ( &u2_Host.ver_e[u2_Host.kno_w] )


  /** Functions.
  **/
    /*  Urbit time: 128 bits, leap-free.
    **
    **  High 64 bits: 0x8000.000c.cea3.5380 + Unix time at leap 25 (Jul 2012)
    **  Low 64 bits: 1/2^64 of a second.
    **
    **  Seconds per Gregorian 400-block: 12.622.780.800
    **  400-blocks from 0 to 0AD: 730.692.561
    **  Years from 0 to 0AD: 292.277.024.400
    **  Seconds from 0 to 0AD: 9.223.372.029.693.628.800
    **  Seconds between 0A and Unix epoch: 62.167.219.200
    **  Seconds before Unix epoch: 9.223.372.091.860.848.000
    **  The same, in C hex notation: 0x8000000cce9e0d80ULL
    **
    **  New leap seconds after July 2012 (leap second 25) are ignored.  The
    **  platform OS will not ignore them, of course, so they must be detected
    **  and counteracted.  Perhaps this phenomenon will soon find an endpoint.
    */
      /* u2_time_sec_in(): urbit seconds from unix time.  
      **
      ** Adjust (externally) for future leap secs!
      */
        c3_d
        u2_time_sec_in(c3_w unx_w);

      /* u2_time_sec_out(): unix time from urbit seconds.  
      **
      ** Adjust (externally) for future leap secs!
      */
        c3_w
        u2_time_sec_out(c3_d urs_d);

      /* u2_time_fsc_in(): urbit fracto-seconds from unix microseconds.
      */
        c3_d
        u2_time_fsc_in(c3_w usc_w);

      /* u2_time_fsc_out: unix microseconds from urbit fracto-seconds.
      */
        c3_w
        u2_time_fsc_out(c3_d ufc_d);

      /* u2_time_in_tv(): urbit time from struct timeval.
      */
        u2_atom
        u2_time_in_tv(struct timeval* tim_tv);

      /* u2_time_out_tv(): struct timeval from urbit time.
      */
        void
        u2_time_out_tv(struct timeval* tim_tv, u2_noun now);

      /* u2_time_in_ts(): urbit time from struct timespec.
      */
        u2_atom
        u2_time_in_ts(struct timespec* tim_ts);

      /* u2_time_out_ts(): struct timespec from urbit time.
      */
        void
        u2_time_out_ts(struct timespec* tim_ts, u2_noun now);


    /**  Filesystem (new api).
    **/
      /* u2_walk_load(): load file or bail.
      */
        u2_noun
        u2_walk_load(c3_c* pas_c);

      /* u2_walk_safe(): load file or 0.
      */
        u2_noun
        u2_walk_safe(c3_c* pas_c);

      /* u2_walk_save(): save file or bail.
      */
        void
        u2_walk_save(c3_c* pas_c, u2_noun tim, u2_atom pad);

      /* u2_sync_reck(): traverse filesystem for changes -> lamb
      */
        u2_noun
        u2_sync_reck(u2_reck* rec_u);

      /* u2_walk(): traverse `dir_c` to produce an arch, updating `old`.
      */
        u2_noun
        u2_walk(u2_reck* rec_u, const c3_c* dir_c, u2_noun old);

      /* u2_path(): C unix path in computer for file or directory. 
      */
        c3_c*
        u2_path(u2_bean fyl, u2_noun pax);

    /**  Filesystem (old api).
    **/
      /* u2_ve_file(): load internal file as atom from local or system.
      */
        u2_weak
        u2_ve_file(c3_c* ext_c, u2_noun tah);

      /* u2_ve_frep(): load [.~ %rep myp {now} tah].
      **
      **   File is either ~ or [nbytes mdate atom].
      */
        u2_noun
        u2_ve_frep(u2_noun myp, u2_noun tah);

      /* u2_ve_date(): date internal file.
      */
        c3_d
        u2_ve_date(c3_c* ext_c, u2_noun tah);

      /* u2_ve_save(): save internal file as atom.
      */
        u2_bean
        u2_ve_save(c3_c* ext_c, u2_noun tah, u2_noun dat);

      /* u2_ve_zeus(): prayer to internal file path.  Return unit.
      */
        u2_noun
        u2_ve_zeus(u2_noun hap);

    /**  Output.
    **/
      /* u2_ve_tank(): print a tank at `tab`.
      */
        void
        u2_ve_tank(c3_l tab_l, u2_noun tac);


    /**  Kernel control.
    **/
      /* u2_reck_line(): apply a reck line (protected).
      */
        void
        u2_reck_line(u2_reck* rec_u, u2_noun lin);

      /* u2_reck_http_request(): hear http request on channel.
      */
        void
        u2_reck_http_request(u2_reck* rec_u, 
                             u2_bean  sec,
                             u2_noun  pox, 
                             u2_noun  req);

      /* u2_reck_http_respond(): apply http response.
      */
        void
        u2_reck_http_respond(u2_reck* rec_u, u2_noun pox, u2_noun rep);

      /* u2_reck_boot(): boot the reck engine (unprotected).
      */
        void
        u2_reck_boot(u2_reck* rec_u);

      /* u2_reck_launch(): launch the reck engine (unprotected).
      */
        u2_bean
        u2_reck_launch(u2_reck* rec_u);

      /* u2_reck_peek(): query the reck namespace (protected).
      */
        u2_noun
        u2_reck_peek(u2_reck* rec_u, u2_noun our, u2_noun hap);

      /* u2_reck_keep(): measure timer.
      */
        u2_noun 
        u2_reck_keep(u2_reck* rec_u, u2_noun hap);

      /* u2_reck_poke(): insert and apply an input ovum (protected).
      */
        u2_noun
        u2_reck_poke(u2_reck* rec_u, u2_noun ovo);

      /* u2_reck_prick(): query the reck namespace (unprotected).
      */
        u2_noun
        u2_reck_prick(u2_reck* rec_u, u2_noun our, u2_noun hap);

      /* u2_reck_kick(): handle effect.
      */
        void
        u2_reck_kick(u2_reck* rec_u, u2_noun ovo);

      /* u2_reck_sync(): poll and apply sync events (protected).
      */
        void
        u2_reck_sync(u2_reck* rec_u);

      /* u2_reck_time(): set the reck time.
      */
        void
        u2_reck_time(u2_reck* rec_u);
     
      /* u2_reck_wind(): set the reck time artificially.
      */
        void
        u2_reck_wind(u2_reck* rec_u, u2_noun now);

      /* u2_reck_plan(): queue ovum (external).
      */
        void
        u2_reck_plan(u2_reck* rec_u,
                     u2_noun  pax,
                     u2_noun  fav);

      /* u2_reck_plow(): queue ovum list in order (external).
      */
        void
        u2_reck_plow(u2_reck* rec_u, u2_noun ova);

      /* u2_reck_work(): flush ova (unprotected).
      */
        void
        u2_reck_work(u2_reck* rec_u);

    /**  Execution system.
    **/
      /* u2_ve_tag: simple string from stage number.
      */
        u2_noun
        u2_ve_tag(c3_w a_w);

      /* u2_ve_bone(): direct execution from kernel, using ":!%".
      */
        u2_noun
        u2_ve_bone(c3_c *bon_c);

      /* u2_ve_seed(): return kernel seed.
      */
        u2_noun
        u2_ve_seed();

      /* u2_ve_slap(): use slap gate. 
      */
        u2_noun
        u2_ve_slap(u2_noun vax, u2_noun gen);

      /* u2_ve_slam(): use slam gate. 
      */
        u2_noun
        u2_ve_slam(u2_noun gat, u2_noun sam);

      /* u2_ve_slop(): use slop gate. 
      */
        u2_noun
        u2_ve_slop(u2_noun hed, u2_noun tal);

      /* u2_ve_scot(): use scot (atom printer).
      */
        u2_noun
        u2_ve_scot(u2_noun fom, u2_noun dat);

      /* u2_ve_sell(): use sell gate. 
      */
        u2_noun
        u2_ve_sell(u2_noun vax);

      /* u2_ve_skol(): use skol gate. 
      */
        u2_noun
        u2_ve_skol(u2_noun typ);

      /* u2_ve_ream(): use ream gate.
      */
        u2_noun
        u2_ve_ream(u2_noun txt);

      /* u2_ve_rain(): use rain gate.
      */
        u2_noun
        u2_ve_rain(u2_noun bon, u2_noun txt);

      /* u2_ve_slac(): slap with C string as feature.
      */
        u2_noun
        u2_ve_slac(u2_noun vax, const c3_c* sam_c);

      /* u2_ve_slan(): slap with C string as gene.
      */
        u2_noun
        u2_ve_slan(u2_noun vax, const c3_c* sam_c);

      /* u2_ve_use(): use specified tool.
      */
        u2_noun 
        u2_ve_use(const c3_c* wit_c);

      /* u2_ve_set(): set specified tool.
      */
        void
        u2_ve_set(const c3_c* wit_c, u2_noun zam);

      /* u2_ve_step(): replace standard tool gate with new core.
      */
        void
        u2_ve_step(const c3_c* wit_c, u2_noun wip);

      /* u2_ve_hard(): use standard tool gate without type check.
      */
        u2_noun
        u2_ve_hard(const c3_c* wit_c, c3_c* fun_c, u2_noun arg);

      /* u2_ve_soft(): use standard tool gate against vase.
      */
        u2_noun
        u2_ve_soft(const c3_c* wit_c, c3_c* fun_c, u2_noun vos);

      /* u2_ve_meat(): return noun of vase.
      */
        u2_noun 
        u2_ve_meat(u2_noun vos);

      /* u2_ve_here(): overlay path search.
      */
        u2_noun
        u2_ve_here(u2_noun wis);

    /**  Boot logic.
    **/
      /* u2_ve_grab(): garbage-collect the world, plus roots.
      */
        void
        u2_ve_grab(u2_noun som, ...);

      /* u2_ve_gunn(): produce a gunn, of any vintage.
      */
        u2_noun
        u2_ve_gunn();

      /* u2_ve_init(): boot the kernel at `kno`.
      */
        void
        u2_ve_init(c3_w kno_w);

    /**  Console and command line.  
    **/
      /* u2_ve_dump_columns(): return screen column width from OS.
      */
        c3_l
        u2_ve_dump_columns(void);

      /* u2_ve_dump_tape(): print a tape of text.
      */
        void
        u2_ve_dump_tape(u2_noun tep);

      /* u2_ve_dump_wall(): print a wall of text.
      */
        void
        u2_ve_dump_wall(u2_noun wol);

      /* u2_ve_sway(): print trace stack.
      */
        void
        u2_ve_sway(c3_l tab_l, u2_noun tax);

      /* u2_ve_wine(): analyze and express error result.
      */
        void
        u2_ve_wine(u2_noun how);

      /* u2_ve_line(): execute a command line, fully protected.
      */
        void
        u2_ve_line(c3_c* lin_c);

      /* u2_ve_line_boot(): boot the command-line shell.
      */
        void
        u2_ve_line_boot(void);

      /* u2_ve_launch(): call neck launch fn.
      */
        void
        u2_ve_launch(void);

      /* u2_ve_sync(): filesystem sync, unprotected.
      */
        void
        u2_ve_sync(void);


    /**  Main loop, new style.
    **/
      /* u2_lo_call(): central callback.
      */
        void
        u2_lo_call(u2_reck*        rec_u,
                   struct ev_loop* lup_u,
                   void*           wev_u,
                   u2_noun         how,
                   c3_i            revents);

      /* u2_lo_loop(): enter main event loop.
      */
        void
        u2_lo_loop(u2_reck* rec_u, 
                   u2_noun cpu, 
                   u2_noun meh,
                   u2_bean rez);

      /* u2_lo_bail(): clean up all event state.
      */
        void
        u2_lo_bail(u2_reck* rec_u);

    /**  Terminal, new style.
    **/
      /* u2_term_ef_boil(): initial effects for restored server.
      */
        void
        u2_term_ef_boil(u2_reck* rec_u,
                        c3_l     old_l,
                        c3_l     ono_l);

      /* u2_term_ef_bake(): initial effects for new server.
      */
        void
        u2_term_ef_bake(u2_reck* rec_u,
                        u2_noun  fav);

      /* u2_term_ef_blit(): send %blit effect to to terminal.
      */
        void
        u2_term_ef_blit(u2_reck* rec_u,
                        c3_l     tid_l,
                        u2_noun  blt);

      /* u2_term_io_init(): initialize terminal I/O.
      */
        void 
        u2_term_io_init(u2_reck* rec_u);

      /* u2_term_io_exit(): terminate terminal I/O.
      */
        void 
        u2_term_io_exit(u2_reck* rec_u);

      /* u2_term_io_spin(): start terminal server(s).
      */
        void
        u2_term_io_spin(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_term_io_stop(): stop terminal servers.
      */
        void
        u2_term_io_stop(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_term_io_poll(): update terminal IO state.
      */
        void
        u2_term_io_poll(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_term_io_suck(): read terminal bytes.
      */
        void
        u2_term_io_suck(u2_reck*      rec_u,
                        struct ev_io* wax_u);

      /* u2_term_io_fuck(): write terminal bytes.
      */
        void
        u2_term_io_fuck(u2_reck*      rec_u,
                        struct ev_io* wax_u);

        
      /* u2_term_io_hija(): hijack console for cooked print.
      */
        FILE*
        u2_term_io_hija(void);

      /* u2_term_io_loja(): release console from cooked print.
      */
        void
        u2_term_io_loja(int x);

      /* uL, uH: wrap hijack/lojack around fprintf.
      **
      **  uL(fprintf(uH, ...));
      */
#       define uH    u2_term_io_hija()
#       define uL(x) u2_term_io_loja(x)


    /**  Ames, packet networking.
    **/
      /* u2_ames_ef_send(): send packet to network.
      */
        void
        u2_ames_ef_send(u2_reck* rec_u,
                        u2_noun  lan,
                        u2_noun  pac);

      /* u2_ames_io_init(): initialize ames I/O.
      */
        void 
        u2_ames_io_init(u2_reck* rec_u);

      /* u2_ames_io_exit(): terminate ames I/O.
      */
        void 
        u2_ames_io_exit(u2_reck* rec_u);

      /* u2_ames_io_spin(): start ames server(s).
      */
        void
        u2_ames_io_spin(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_ames_io_stop(): stop ames servers.
      */
        void
        u2_ames_io_stop(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_ames_io_poll(): update ames IO state.
      */
        void
        u2_ames_io_poll(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_ames_io_fuck(): output event on connection socket.
      */
        void
        u2_ames_io_fuck(u2_reck*      rec_u,
                        struct ev_io* wax_u);

      /* u2_ames_io_suck(): input event on listen socket.
      */
        void
        u2_ames_io_suck(u2_reck*      rec_u,
                        struct ev_io* wax_u);

      /* u2_ames_io_time(): time event on ames channel.
      */
        void
        u2_ames_io_time(u2_reck*         rec_u,
                        struct ev_timer* tim_u);

    /**  HTTP, new style.
    **/
      /* u2_http_ef_thou(): send %thou effect to http. 
      */
        void
        u2_http_ef_thou(u2_reck* rec_u,
                        c3_l     coq_l,
                        c3_l     seq_l,
                        u2_noun  rep);

      /* u2_http_ef_bake(): create new http server.
      */
        void
        u2_http_ef_bake(u2_reck* rec_u);

      /* u2_http_io_init(): initialize http I/O.
      */
        void 
        u2_http_io_init(u2_reck* rec_u);

      /* u2_http_io_exit(): terminate http I/O.
      */
        void 
        u2_http_io_exit(u2_reck* rec_u);

      /* u2_http_io_spin(): start http server(s).
      */
        void
        u2_http_io_spin(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_http_io_stop(): stop http servers.
      */
        void
        u2_http_io_stop(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_http_io_poll(): update http IO state.
      */
        void
        u2_http_io_poll(u2_reck*        rec_u,
                        struct ev_loop* lup_u);

      /* u2_http_io_fuck_conn(): output event on connection socket.
      */
        void
        u2_http_io_fuck_conn(u2_reck*      rec_u,
                             struct ev_io* wax_u);

      /* u2_http_io_suck_lisn(): input event on listen socket.
      */
        void
        u2_http_io_suck_lisn(u2_reck*      rec_u,
                             struct ev_io* wax_u);

      /* u2_http_io_suck_conn(): input event on connection socket.
      */
        void
        u2_http_io_suck_conn(u2_reck*      rec_u,
                             struct ev_io* wax_u);
