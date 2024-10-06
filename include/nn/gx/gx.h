#ifndef _NN_GX_H_
#define _NN_GX_H_

#ifdef __cplusplus
extern "C" {
#endif

#define NNGX_ALLOCATOR_REGION_FCRAM  0x10000
#define NNGX_ALLOCATOR_REGION_VRAM_A 0x20000
#define NNGX_ALLOCATOR_REGION_VRAM_B 0x30000

#define NNGX_ALLOCATOR_USAGE_MEM_SYSTEM         0x100
#define NNGX_ALLOCATOR_USAGE_MEM_TEXTURE        0x101
#define NNGX_ALLOCATOR_USAGE_MEM_VERTEX_BUFFER  0x102
#define NNGX_ALLOCATOR_USAGE_MEM_RENDER_BUFFER  0x103
#define NNGX_ALLOCATOR_USAGE_MEM_DISPLAY_BUFFER 0x104
#define NNGX_ALLOCATOR_USAGE_MEM_COMMAND_BUFFER 0x105

#define NNGX_CMDLIST_PARAMETER_RUN_MODE               0x200
#define NNGX_CMDLIST_PARAMETER_IS_RUNNING             0x201
#define NNGX_CMDLIST_PARAMETER_USED_BUFFER_SIZE       0x202
#define NNGX_CMDLIST_PARAMETER_USED_REQUEST_COUNT     0x203
#define NNGX_CMDLIST_PARAMETER_MAX_BUFFER_SIZE        0x204
#define NNGX_CMDLIST_PARAMETER_MAX_REQUEST_COUNT      0x205
#define NNGX_CMDLIST_PARAMETER_TOP_BUFFER_ADDRESS     0x206
#define NNGX_CMDLIST_PARAMETER_BINDING                0x207
#define NNGX_CMDLIST_PARAMETER_CURRENT_BUFFER_ADDRESS 0x208
#define NNGX_CMDLIST_PARAMETER_RUN_BUFFER_SIZE        0x209
#define NNGX_CMDLIST_PARAMETER_RUN_REQUEST_COUNT      0x20A
#define NNGX_CMDLIST_PARAMETER_TOP_REQUEST_ADDRESS    0x20B
#define NNGX_CMDLIST_PARAMETER_NEXT_REQUEST_TYPE      0x20C
#define NNGX_CMDLIST_PARAMETER_NEXT_REQUEST_INFO      0x20D
#define NNGX_CMDLIST_PARAMETER_HW_STATE               0x20E
#define NNGX_CMDLIST_PARAMETER_GAS_UPDATE             0x20F

#define NNGX_DISPLAY_0    0x400
#define NNGX_DISPLAY_1    0x401
#define NNGX_DISPLAY_BOTH 0x402
#define NNGX_DISPLAY0_EXT 0x410

#define NNGX_DISPLAY_BUFFER_ADDRESS 0x600
#define NNGX_DISPLAY_BUFFER_FORMAT  0x601
#define NNGX_DISPLAY_BUFFER_WIDTH   0x602
#define NNGX_DISPLAY_BUFFER_HEIGHT  0x603

typedef void*(*nngxAllocator)(s32, s32, s32, s32);
typedef void*(*nngxDeallocator)(s32, s32, s32, void*);

bool nngxInitialize(nngxAllocator, nngxDeallocator);

void nngxGenCmdlists(s32 numCmdListIDs, u32* cmdListIDs);
void nngxBindCmdlist(u32 cmdList);
void nngxCmdlistStorage(s32 bufferSize, s32 numRequests);
void nngxSetCmdlistParameteri(s32 param, s32 value);
void nngxActiveDisplay(s32 display);
void nngxGenDisplaybuffers(s32 numDisplayBufferIDs, u32* displayBufferIDs);
void nngxDisplaybufferStorage(s32 format, s32 width, s32 height, s32 area);
void nngxGetDisplaybufferParameteri(s32 type, s32* parameter);
void nngxDisplayEnv(s32 displayX, s32 displayY);
void nngxRunCmdlist(void);

#ifdef __cplusplus
}
#endif

#endif // _NN_GX_H_
