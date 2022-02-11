module;

#include <cmp_plot.h>
#include <example_utils.h>
#include <juce_gui_extra/juce_gui_extra.h>

export module custom_graph_attributes;

namespace examples {
export class custom_graph_attributes : public juce::Component {
  // Declare plot object.
  cmp::Plot m_plot;

 public:
  custom_graph_attributes() : m_plot{cmp::Plot()} {
    setSize(1200, 800);

    // Add the plot object as a child component.
    addAndMakeVisible(m_plot);

    const auto length = (1 << 11);
    constexpr auto length_1st_graph = 10;

    // Create some data to visulize.
    auto y_data = {
        cmp::generateSineWaveVector(length_1st_graph, -17.0f, 14.0f, 1.0f),
        cmp::generateSineWaveVector(length, -5.0f, 6.0f, 3.0f),
        cmp::generateSineWaveVector(length, -5.0f, 2.0f, 6.0f)};

    auto x_data_1st_graph = []() {
      auto v = std::vector<float>(10);
      cmp::iota_delta(v.begin(), v.end(), 1.0f,
                      float(length) / float(v.size()));
      return v;
    }();

    // Setting graph attributes.
    auto graph_attributes = cmp::GraphAttributeList(y_data.size());
    graph_attributes[0].graph_colour = juce::Colours::pink;
    graph_attributes[0].marker = cmp::Marker::Type::Pentagram;

    graph_attributes[1].graph_colour = juce::Colours::blueviolet;
    graph_attributes[1].path_stroke_type = juce::PathStrokeType(10.0f);

    graph_attributes[2].dashed_lengths = {10.0f, 20.0f, 10.0f};

    // Plot some values.
    m_plot.plot(y_data, {x_data_1st_graph, {}, {}}, graph_attributes);
  };

  void resized() override {
    // Set the bounds of the plot to fill the whole window.
    m_plot.setBounds(getBounds());
  };
};
}  // namespace examples
