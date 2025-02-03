class PostsController < ApplicationController
  before_action :authenticate_user!, except: [:index]

  def index
    @posts = Post.where(online: true).order('created_at DESC')  # Only show online posts
  end

  def new
    @post = Post.new
  end

  def create
    @post = Post.new(post_params)

    if @post.save
      redirect_to @post
    else
      render 'new'
    end
  end

  def show
    @post = Post.find(params[:id])
  end

  def edit
    @post = Post.find(params[:id])
  end

  def update
    @post = Post.find(params[:id])

    if @post.update(post_params)
      redirect_to @post
    else
      render 'edit'
    end
  end

  def destroy
    @post = Post.find(params[:id])
    @post.destroy

    redirect_to root_path
  end

  # New action to toggle the 'online' status of a post
  def toggle_online
    @post = Post.find(params[:id])
    @post.update(online: !@post.online)  # Toggle the boolean value of 'online'
    redirect_to @post
  end

  private

  def post_params
    params.require(:post).permit(:title, :body, :online)  # Allow the 'online' field to be updated
  end
end
