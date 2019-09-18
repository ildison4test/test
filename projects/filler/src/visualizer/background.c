/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:37:05 by cormund           #+#    #+#             */
/*   Updated: 2019/09/18 16:43:47 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void		bgrnt_board(t_vis *vis, t_game *game)
{
	vis->bgrnd_board.x = BG_BOARD_X;
	vis->bgrnd_board.y = BG_BOARD_Y;
	game->size_rect.x = (SCREEN_WIDTH - BG_BOARD_X - 25) / game->size_board.x;
	game->size_rect.y = (SCREEN_HEIGHT - BG_BOARD_Y - 25) / game->size_board.y;
	vis->bgrnd_board.w = game->size_rect.x * game->size_board.x;
	vis->bgrnd_board.h = game->size_rect.y * game->size_board.y;
}

static void		logo(t_vis *vis)
{
	SDL_Surface	*text;
	SDL_Color	color;

	color.r = CLR_LOGO >> 16 & 0xff;
	color.g = CLR_LOGO >> 8 & 0xff;
	color.b = CLR_LOGO & 0xff;
	TTF_SizeText(vis->font_logo, LOGO, &vis->size_logo.w, &vis->size_logo.h);
	vis->size_logo.x = 20;
	vis->size_logo.y = 15;
	text = TTF_RenderText_Blended(vis->font_logo, LOGO, color);
	vis->logo = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

static void		head_wins(t_vis *vis)
{
	t_pnt		size_text;

	TTF_SizeText(vis->font_text, INFO, &size_text.x, &size_text.y);
	vis->up_win[0].x = vis->size_logo.x - 10;
	vis->up_win[0].y = vis->size_logo.y - 10;
	vis->up_win[0].w = vis->size_logo.w + 20;
	vis->up_win[0].h = vis->size_logo.h + 25;
	vis->up_win[1].x = vis->info_win[0].x;
	vis->up_win[1].y = vis->info_win[0].y;
	vis->up_win[1].w = vis->up_win[0].w;
	vis->up_win[1].h = size_text.y * 1.5;
	vis->up_win[2].x = vis->info_win[0].x;
	vis->up_win[2].y = vis->info_win[1].y;
	vis->up_win[2].w = vis->up_win[0].w;
	vis->up_win[2].h = vis->up_win[1].h;
	vis->up_win[3].x = vis->info_win[0].x;
	vis->up_win[3].y = vis->info_win[2].y;
	vis->up_win[3].w = vis->up_win[0].w;
	vis->up_win[3].h = vis->up_win[1].h;
	vis->up_win[4].x = vis->info_win[0].x;
	vis->up_win[4].y = vis->info_win[3].y;
	vis->up_win[4].w = vis->up_win[0].w;
	vis->up_win[4].h = vis->up_win[1].h;
}

static void		wins_for_info(t_vis *vis)
{
	t_pnt		size_text;

	TTF_SizeText(vis->font_text, INFO, &size_text.x, &size_text.y);
	vis->info_win[0].x = vis->size_logo.x - 10;
	vis->info_win[0].y = vis->size_logo.y + vis->size_logo.h + 40;
	vis->info_win[0].w = vis->size_logo.w + 20;
	vis->info_win[0].h = size_text.y * 5;
	vis->info_win[1].x = vis->info_win[0].x;
	vis->info_win[1].y = vis->info_win[0].y + vis->info_win[0].h + 30;
	vis->info_win[1].w = vis->info_win[0].w;
	vis->info_win[1].h = size_text.y * 6;
	vis->info_win[2].x = vis->info_win[1].x;
	vis->info_win[2].y = vis->info_win[1].y + vis->info_win[1].h + 30;
	vis->info_win[2].w = vis->info_win[0].w;
	vis->info_win[2].h = size_text.y * 5;
	vis->info_win[3].x = vis->info_win[2].x;
	vis->info_win[3].y = vis->info_win[2].y + vis->info_win[2].h + 30;
	vis->info_win[3].w = vis->info_win[0].w;
	vis->info_win[3].h = size_text.y * 4;
}

void			head(t_vis *vis)
{
	SDL_Surface	*text;
	SDL_Color	color;

	color.r = CLR_P >> 16 & 0xff;
	color.g = CLR_P >> 8 & 0xff;
	color.b = CLR_P & 0xff;
	vis->color_text = color;
	text = TTF_RenderText_Blended(vis->font_text, INFO, color);
	vis->head[0] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, KEYS, color);
	vis->head[1] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, PROGRESS, color);
	vis->head[2] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, SCORE, color);
	vis->head[3] = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

void			background(t_game *game, t_vis *vis)
{
	bgrnt_board(vis, game);
	logo(vis);
	wins_for_info(vis);
	head_wins(vis);
	head(vis);
	info_win(vis, game);
	control_keys(vis);
}