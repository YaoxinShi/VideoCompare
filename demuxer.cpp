#include "demuxer.h"
#include "ffmpeg.h"
#include <iostream>
#include <assert.h>

Demuxer::Demuxer(const std::string &file_name) {
	av_register_all();
	if (avformat_open_input(&format_context_, file_name.c_str(), nullptr, nullptr) < 0)
	{
		printf("avformat_open_input() fail. Does the file exist?\n");
		assert(0);
	}
	if (avformat_find_stream_info(format_context_, nullptr) < 0)
	{
		printf("avformat_find_stream_info() fail.\n");
		assert(0);
	}
	video_stream_index_ = av_find_best_stream(format_context_, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (video_stream_index_ < 0)
	{
		printf("av_find_best_stream() fail.\n");
		assert(0);
	}
}

Demuxer::~Demuxer() {
	avformat_close_input(&format_context_);
}

AVCodecParameters* Demuxer::video_codec_parameters() {
	return format_context_->streams[video_stream_index_]->codecpar;
}

int Demuxer::video_stream_index() const {
	return video_stream_index_;
}

AVRational Demuxer::time_base() const {
	return format_context_->streams[video_stream_index_]->time_base;
}

bool Demuxer::operator()(AVPacket &packet) {
	return av_read_frame(format_context_, &packet) >= 0;
}

bool Demuxer::seek(const float position, const bool backward) {
    int64_t seekTarget = int64_t(position * 1000000.0f);

    return av_seek_frame(format_context_, -1, seekTarget, backward ? AVSEEK_FLAG_BACKWARD : 0) >= 0;
}