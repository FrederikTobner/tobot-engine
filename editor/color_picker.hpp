namespace Tobot::Editor {
    class ColorPicker {
        public:
            ColorPicker(bool & show_color_picker);
            auto render() -> void;

        private:
            bool & show_color_picker;
    };
} // namespace Tobot::Editor