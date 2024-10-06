#pragma once

#include <non_matchings.h>
#include <nn/os/os.h>
#include <nn/Handle.h>

namespace nn {

namespace y2r {

namespace CTR {

class StandardCoefficient;

class BlockAlignment;

class OutputFormat;

class InputFormat;

class Rotation;

namespace detail {

UNK_RETURN SetAlpha(short);

namespace Y2r {

UNK_RETURN SetAlpha(short);

UNK_RETURN SetTransferEndInterrupt(bool);

UNK_RETURN SetStandardCoefficient(nn::y2r::CTR::StandardCoefficient);

UNK_RETURN GetTransferEndEvent(nn::Handle*);

UNK_RETURN SetInputLineWidth(short);

UNK_RETURN SetBlockAlignment(nn::y2r::CTR::BlockAlignment);

UNK_RETURN IsBusyConversion(bool*);

UNK_RETURN DriverInitialize();

UNK_RETURN StartConversion();

UNK_RETURN SetOutputFormat(nn::y2r::CTR::OutputFormat);

UNK_RETURN StopConversion();

UNK_RETURN SetInputFormat(nn::y2r::CTR::InputFormat);

UNK_RETURN DriverFinalize();

UNK_RETURN SetInputLines(short);

UNK_RETURN SetReceiving(nn::Handle, unsigned int, unsigned int, short, short);

UNK_RETURN SetSendingY(nn::Handle, unsigned int, unsigned int, short, short);

UNK_RETURN SetSendingV(nn::Handle, unsigned int, unsigned int, short, short);

UNK_RETURN SetSendingU(nn::Handle, unsigned int, unsigned int, short, short);

UNK_RETURN SetRotation(nn::y2r::CTR::Rotation);

UNK_RETURN PingProcess(unsigned char*);

} // Y2r

UNK_RETURN SetTransferEndInterrupt(bool);

UNK_RETURN SetStandardCoefficient(nn::y2r::CTR::StandardCoefficient);

UNK_RETURN GetTransferEndEvent(nn::os::Event*);

UNK_RETURN SetInputLineWidth(short);

UNK_RETURN SetBlockAlignment(nn::y2r::CTR::BlockAlignment);

UNK_RETURN IsBusyConversion();

UNK_RETURN StartConversion();

UNK_RETURN SetOutputFormat(nn::y2r::CTR::OutputFormat);

UNK_RETURN StopConversion();

UNK_RETURN SetInputFormat(nn::y2r::CTR::InputFormat);

UNK_RETURN InitializeBase(nn::Handle*, char const*);

UNK_RETURN SetInputLines(short);

UNK_RETURN SetReceiving(unsigned int, unsigned int, short, short);

UNK_RETURN FinalizeBase(nn::Handle*);

UNK_RETURN SetSendingY(unsigned int, unsigned int, short, short);

UNK_RETURN SetSendingV(unsigned int, unsigned int, short, short);

UNK_RETURN SetSendingU(unsigned int, unsigned int, short, short);

UNK_RETURN SetRotation(nn::y2r::CTR::Rotation);

} // detail

} // CTR

} // y2r

} // nn

