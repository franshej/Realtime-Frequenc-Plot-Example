/**
 * @file scp_zoom.h
 *
 * @brief Componenet for drawing the zoom area and store the zoom start and end
 * postion.
 *
 * @ingroup SimpleCustomPlotInternal
 *
 * @author Frans Rosencrantz
 * Contact: Frans.Rosencrantz@gmail.com
 *
 */

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <scp_datamodels.h>

namespace scp {
/**
 * \class Zoom
 * \brief A class for drawing the zoom area.
 *
 * The idea is to use this component to draw the zoom area and store the start
 * and end position.
 */
class Zoom : public juce::Component {
 public:
  /** @brief Set the start zoom area postion.
   *
   *  Set the start screen postion of zoom area.
   *
   *  @param start_position the start position of the zoom area.
   *  @return void.
   */
  void setStartPosition(const juce::Point<int>& start_position) noexcept;

  /** @brief Set the end zoom area postion.
   *
   *  Set the end screen postion of zoom area.
   *
   *  @param end_position the end position of the zoom area.
   *  @return void.
   */
  void setEndPosition(const juce::Point<int>& end_position) noexcept;

  /** @brief Get the start zoom area postion.
   *
   *  Get the start screen postion of zoom area.
   *
   *  @return a point of the start postion.
   */
  juce::Point<int> getStartPosition() const noexcept;

  /** @brief Get the end zoom area postion.
   *
   *  Get the end screen postion of zoom area.
   *
   *  @return a point of the end postion.
   */
  juce::Point<int> getEndPosition() const noexcept;

  /** @brief Reset the start and end postions.
   *
   *  Set the start and end postion to 0 -> {x = 0,y = 0}.
   *
   *  @return void.
   */
  void reset() noexcept;

  /** @internal */
  void resized() override;
  /** @internal */
  void paint(juce::Graphics& g) override;
  /** @internal */
  void lookAndFeelChanged() override;

 private:
  LookAndFeelMethodsBase* m_lookandfeel;

  juce::Point<int> m_start_pos, m_end_pos;
};
}  // namespace scp
