#ifndef _APDOOM_
#define _APDOOM_


#ifdef __cplusplus
extern "C"
{
#endif


#define AP_EPISODE_COUNT 3
#define AP_LEVEL_COUNT 9
    

typedef struct
{
    int keys[3];
    int check_count;

} ap_level_info_t;


typedef struct
{
    int completed;
    int keys[3];
    int check_count;

} ap_level_state_t;


typedef struct
{
    ap_level_state_t level_states[AP_EPISODE_COUNT][AP_LEVEL_COUNT];
    
} ap_state_t;


typedef struct
{
    const char* ip;
    const char* game;
    const char* player_name;
    const char* passwd;
    void (*message_callback)(const char*);
    void (*give_item_callback)(int doom_type);
} ap_settings_t;


extern ap_level_info_t ap_level_infos[AP_EPISODE_COUNT][AP_LEVEL_COUNT];
extern ap_state_t ap_state;
extern int ap_is_in_game; // Don't give items when in menu (Or when dead on the ground).


int apdoom_init(ap_settings_t* settings);
void apdoom_check_location(int ep, int map, int index);
void apdoom_victory();
void apdoom_update();
const char* apdoom_get_seed();

#ifdef __cplusplus
}
#endif


#endif
