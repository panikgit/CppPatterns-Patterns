// file pimpl.h
#ifndef PIMPL_H_
#define PIMPL_H_

#include <memory>

namespace pimpl
{

    class ImplInterface
    {
    public:
        virtual ~ImplInterface() = default;

        virtual void implDo() = 0;
    };


    class Outer
    {
    public:
        Outer();

        ImplInterface* operator->() { return impl.get(); }

    private:
        std::unique_ptr<ImplInterface> impl;
    };

} // namespace pimpl

#endif PIMPL_H_


// file pimpl.cpp

namespace pimpl
{

    class Impl : public ImplInterface
    {
    public:
        void implDo() override { }
    };


    Outer::Outer()
        : impl(std::make_unique<Impl>())
    { }

} // namespace pimpl