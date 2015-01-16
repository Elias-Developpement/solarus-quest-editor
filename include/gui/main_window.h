/*
 * Copyright (C) 2014-2015 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus Quest Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUSEDITOR_MAIN_WINDOW_H
#define SOLARUSEDITOR_MAIN_WINDOW_H

#include "quest.h"
#include "ui_main_window.h"
#include <QMainWindow>

class QuestManager;
class QToolButton;

/**
 * @brief Main window of the quest editor.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  MainWindow(QWidget* parent);

  void initialize_geometry_on_screen();
  Quest& get_quest();
  void close_quest();
  bool open_quest(const QString& quest_path);
  void open_file(Quest& quest, const QString& path);

private slots:

  // Menu actions.
  void on_action_new_quest_triggered();
  void on_action_load_quest_triggered();
  void on_action_save_triggered();
  void on_action_close_triggered();
  void on_action_exit_triggered();
  void on_action_cut_triggered();
  void on_action_copy_triggered();
  void on_action_paste_triggered();
  void on_action_run_quest_triggered();

  void current_editor_changed(int index);
  void editor_zoom_changed(double zoom);

protected:

  virtual void closeEvent(QCloseEvent* event) override;

private:

  bool confirm_close();
  void update_title();
  void upgrade_quest();
  QMenu* create_zoom_menu();

  Ui::MainWindow ui;              /**< The main window widgets. */
  Quest quest;                    /**< The current quest open if any. */

  QMenu* zoom_menu;               /**< The zoom menu. */
  QToolButton* zoom_button;       /**< The zoom toolbar button. */
  QMap<double, QAction*>
      zoom_actions;               /**< Action of each zoom value. */
};

#endif
